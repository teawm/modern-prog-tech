#include "db.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <cstddef>
#include <string>
#include <vector>
#include <cctype>

namespace {

bool looksLikePhone(const std::string& s) {
    if (s.empty()) return false;
    int digits = 0;
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isdigit(uc)) { digits++; continue; }
        if (c == '+' || c == '-' || c == ' ' || c == '(' || c == ')') continue;
        return false;
    }
    return digits >= 10;
}

// Вспомогательная функция для чтения результатов SELECT в вектор Order
std::vector<Order> readOrders(const pqxx::result& r) {
    std::vector<Order> orders;
    orders.reserve(r.size());
    for (const auto& row : r) {
        Order o;
        o.id = row[0].as<int>();
        o.code = row[1].as<std::string>();
        o.phone = row[2].as<std::string>();
        o.article = row[3].as<std::string>();
        o.cell = row[4].as<std::string>();
        o.status = row[5].as<std::string>();
        o.created_at = row[6].as<std::string>();
        orders.push_back(o);
    }
    return orders;
}

} // namespace

Database::Database(const std::string& conn_str)
    : conn_(conn_str)
{
    if (!conn_.is_open())
        throw std::runtime_error("Не удалось подключиться к PostgreSQL");
}

std::vector<Order> Database::listOrders(const std::string& filter) {
    pqxx::work txn(conn_);
    std::string sql = "SELECT id, order_code, COALESCE(phone, ''), "
                      "COALESCE(parcel_article, ''), COALESCE(cell, ''), "
                      "status, to_char(created_at, 'YYYY-MM-DD HH24:MI') "
                      "FROM orders";
                      
    if (!filter.empty()) {
        // Используем txn.quote для защиты от SQL-инъекций (тест 18)
        std::string pattern = txn.quote("%" + filter + "%");
        sql += " WHERE order_code ILIKE " + pattern +
               " OR COALESCE(phone, '') ILIKE " + pattern +
               " OR COALESCE(parcel_article, '') ILIKE " + pattern;
    }
    
    sql += " ORDER BY created_at DESC, id DESC";
    
    auto r = txn.exec(sql);
    txn.commit();
    return readOrders(r);
}

std::string Database::addOrder(const std::string& contact,
                               const std::string& cell) {
    bool is_phone = looksLikePhone(contact);
    std::string phone = is_phone ? contact : "";
    std::string article = is_phone ? "" : contact;

    pqxx::work txn(conn_);
    
    // Вставляем с временным уникальным кодом, чтобы удовлетворить UNIQUE NOT NULL.
    // RETURNING id позволяет получить ID для формирования финального кода PVZ-XXXXXX.
    auto r = txn.exec_params(
        "INSERT INTO orders (order_code, phone, parcel_article, cell) "
        "VALUES ('TMP-' || substr(md5(random()::text || clock_timestamp()::text || pg_backend_pid()::text), 1, 16), "
        "NULLIF($1, ''), NULLIF($2, ''), NULLIF($3, '')) RETURNING id",
        phone, article, cell
    );
    
    int id = r[0][0].as<int>();
    
    std::ostringstream oss;
    oss << "PVZ-" << std::setfill('0') << std::setw(6) << id;
    std::string final_code = oss.str();
    
    txn.exec_params("UPDATE orders SET order_code = $1 WHERE id = $2", final_code, id);
    
    txn.commit();
    return final_code;
}

bool Database::issueOrder(const std::string& code) {
    pqxx::work txn(conn_);
    auto r = txn.exec_params("SELECT status FROM orders WHERE order_code = $1", code);
    
    // Защита от повторной выдачи (тест 13)
    if (r.empty() || r[0][0].as<std::string>() != "ready") {
        return false;
    }
    
    auto u = txn.exec_params(
        "UPDATE orders SET status = 'issued', issued_at = NOW() WHERE order_code = $1", code
    );
    
    txn.commit();
    return u.affected_rows() > 0;
}

bool Database::cancelOrder(const std::string& code) {
    pqxx::work txn(conn_);
    auto r = txn.exec_params("SELECT status FROM orders WHERE order_code = $1", code);
    
    // Защита от отмены уже выданного заказа (тест 15)
    if (r.empty() || r[0][0].as<std::string>() != "ready") {
        return false;
    }
    
    auto u = txn.exec_params(
        "UPDATE orders SET status = 'cancelled' WHERE order_code = $1", code
    );
    
    txn.commit();
    return u.affected_rows() > 0;
}

Report Database::buildReport() {
    pqxx::work txn(conn_);
    Report rep{0, 0, 0};
    
    auto r_ready = txn.exec_params("SELECT COUNT(*) FROM orders WHERE status = $1", "ready");
    auto r_issued = txn.exec_params("SELECT COUNT(*) FROM orders WHERE status = $1", "issued");
    auto r_cancelled = txn.exec_params("SELECT COUNT(*) FROM orders WHERE status = $1", "cancelled");
    
    rep.ready_count = r_ready[0][0].as<int>();
    rep.issued_count = r_issued[0][0].as<int>();
    rep.cancelled_count = r_cancelled[0][0].as<int>();
    
    txn.commit();
    return rep;
}

std::vector<Order> Database::listByStatus(const std::string& status) {
    pqxx::work txn(conn_);
    std::string sql = "SELECT id, order_code, COALESCE(phone, ''), "
                      "COALESCE(parcel_article, ''), COALESCE(cell, ''), "
                      "status, to_char(created_at, 'YYYY-MM-DD HH24:MI') "
                      "FROM orders";
                      
    pqxx::result r;
    if (status.empty()) {
        sql += " ORDER BY created_at DESC, id DESC";
        r = txn.exec(sql);
    } else {
        sql += " WHERE status = $1 ORDER BY created_at DESC, id DESC";
        r = txn.exec_params(sql, status);
    }
    
    txn.commit();
    return readOrders(r);
}

int Database::countClosedOrders() {
    pqxx::work txn(conn_);
    auto r = txn.exec("SELECT COUNT(*) FROM orders WHERE status IN ('issued', 'cancelled')");
    int count = r[0][0].as<int>();
    txn.commit();
    return count;
}

int Database::deleteClosedOrders() {
    pqxx::work txn(conn_);
    auto r = txn.exec("DELETE FROM orders WHERE status IN ('issued', 'cancelled')");
    // Для DELETE/UPDATE используем affected_rows(), а не size()
    int deleted = static_cast<int>(r.affected_rows());
    txn.commit();
    return deleted;
}