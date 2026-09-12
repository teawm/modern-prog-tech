#include "order_calc.h"
// 1. Расчёт скидки
// Описание: возвращает сумму со скидкой в зависимости от стоимости заказа и статуса клиента.
// - Если total < 0, возвращает -1.0 (ошибка).
// - Если total >= 10000: скидка 20% для премиум-клиентов, 15% для обычных.
// - Если total >= 5000: скидка 10% для премиум-клиентов, 5% для обычных.
// - В остальных случаях скидка 0%.
double applyDiscount(double total, bool isPremium) {
    if (total < 0)              // 2
        return -1.0;              // 3
    if (total >= 10000) {       // 4
        if (isPremium) {          // 5
          return total * 0.80;    // 6
        } else {                  
          return total * 0.85;    // 7
        }
    } else if (total >= 5000) { // 8
        if (isPremium) {          // 9
            return total * 0.90;    // 10
        } else {                  
            return total * 0.95;    // 11
        }
    }
    return total;               // 12
}

// 2. Расчёт стоимости доставки
// Описание: возвращает стоимость доставки в зависимости от суммы заказа.
// - Если total < 0, возвращает -1.0 (ошибка).
// - Если total >= 5000, доставка бесплатная (0.0).
// - Иначе доставка стоит 300.0.
double calcShipping(double total) { 
    if (total < 0)        // 2
        return -1.0;        // 3
    if (total <= 5000)    // 4          // ????????????
        return 0.0;         // 5
    return 300.0;         // 6
}

// 3. Итоговая цена
// Описание: вычисляет финальную стоимость заказа с учётом скидки и доставки.
// - Если любой аргумент отрицательный, возвращает -1.0 (ошибка).
// - Если итоговая цена получается отрицательной, она обнуляется (0.0).
// - Результат округляется до двух знаков после запятой.
double finalPrice(double total, double discount, double shipping) {
    if (total < 0 || discount < 0 || shipping < 0)  // 2
        return -1.0;                                  // 3
    double result = total - discount + shipping;    // 4
    if (result < 0)                                 // 5
        result = 0.0;                                 // 6
    return std::round(result * 100) / 100;          // 7
}

// 4. Подсчёт количества дорогих товаров в корзине
// Описание: возвращает количество товаров, цена которых превышает заданный порог.
// - Если вектор пустой, возвращает 0.
// - В противном случае подсчитывает количество элементов > threshold.
int countExpensiveItems(const std::vector<double>& prices, double threshold) {
    int count = 0;                                  // 2
    for (size_t i = 0; i < prices.size(); ++i) {    // 2, 3, 6
        if (prices[i] > threshold) {                  // 4
            count++;                                    // 5
        }
    }
    return count;                                   // 7
}

// 5. Одномерка 
double productOddIndices(const std::vector<double>& prices) {
    double product = 1.0;          // 2
    if (prices.size() < 2) {       // 3
        return 1.0;                // 4
    }
    for (size_t i = 1; i < prices.size(); i += 2) { // 5, 6, 8
        product *= prices[i];      // 7
    }
    return product;                // 9
}

// 6. Двумерка
int sumOddBelowMainDiagonal(const std::vector<std::vector<int>>& A) {
    int sum = 0;                                  // 2
    for (size_t i = 0; i < A.size(); ++i) {       // 3, 4, 10
        for (size_t j = 0; j < i; ++j) {          // 5, 6, 9
            if (A[i][j] % 2 != 0) {               // 7
                sum += A[i][j];                   // 8
            }
        }
    }
    return sum;                                   // 11
}

// 7. Одномерка
void rotatePricesRight(std::vector<double>& prices, int shift) {
    // Ранний выход: пустая корзина или некорректный сдвиг
    if (prices.empty() || shift <= 0) {         // 2
        return;                                 // 3
    }

    size_t n = prices.size();                   // 4, 5
    size_t k = static_cast<size_t>(shift) % n; // нормализация сдвига

    // Если сдвиг кратен размеру, массив не меняется
    if (k == 0) {                               // 6
        return;                                 // 7
    }

    // 1. Разворачиваем первую часть [0, n-k-1]
    size_t left = 0;                            // 8
    size_t right = n - k - 1;                   // 9
    while (left < right) {                      // 10
        std::swap(prices[left], prices[right]); // 11
        ++left;                                 // 12
        --right;                                // 13
    }

    // 2. Разворачиваем вторую часть [n-k, n-1]
    left = n - k;                               // 14
    right = n - 1;                              // 15
    while (left < right) {                      // 16
        std::swap(prices[left], prices[right]); // 17
        ++left;                                 // 18
        --right;                                // 19
    }

    // 3. Разворачиваем весь массив [0, n-1]
    left = 0;                                   // 20
    right = n - 1;                              // 21
    while (left < right) {                      // 22
        std::swap(prices[left], prices[right]); // 23
        ++left;                                 // 24
        --right;                                // 25
    }
}

// 8. Двумерка
double productOddIndexSum(const std::vector<std::vector<double>>& A) {
    double product = 1.0;                           // 2

    for (size_t i = 0; i < A.size(); ++i) {         // 3, 4, 10
        for (size_t j = 0; j < A[i].size(); ++j) {  // 5, 6, 9
            if ((i + j) % 2 != 0) {                 // 7
                product *= A[i][j];                 // 8
            }
        }
    }

    // Если таких элементов не было, product останется 1.0
    return product;                                 // 11
}
