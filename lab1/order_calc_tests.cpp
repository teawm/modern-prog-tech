#include <gtest/gtest.h>
#include <vector>
#include "order_calc.h"

#include <cstddef> // Свои функции

// ====================================================================================================
// Тесты для функции applyDiscount
// ====================================================================================================

TEST(OrderCalcTest, ApplyDiscount_Path1_NegativeTotal) {
    // Путь 1: Условие (total < 0) = True
    EXPECT_DOUBLE_EQ(applyDiscount(-100.0, true), -1.0);
}

TEST(OrderCalcTest, ApplyDiscount_Path2_PremiumOver10k) {
    // Путь 2: (total < 0)=F, (>= 10000)=T, isPremium=T
    // 15000 * 0.80 = 12000
    EXPECT_DOUBLE_EQ(applyDiscount(15000.0, true), 12000.0);
}

TEST(OrderCalcTest, ApplyDiscount_Path3_RegularOver10k) {
    // Путь 3: (total < 0)=F, (>= 10000)=T, isPremium=F
    // 15000 * 0.85 = 12750
    EXPECT_DOUBLE_EQ(applyDiscount(15000.0, false), 12750.0);
}

TEST(OrderCalcTest, ApplyDiscount_Path4_PremiumOver5k) {
    // Путь 4: (total < 0)=F, (>= 10000)=F, (>= 5000)=T, isPremium=T
    // 7000 * 0.90 = 6300
    EXPECT_DOUBLE_EQ(applyDiscount(7000.0, true), 6300.0);
}

TEST(OrderCalcTest, ApplyDiscount_Path5_RegularOver5k) {
    // Путь 5: (total < 0)=F, (>= 10000)=F, (>= 5000)=T, isPremium=F
    // 7000 * 0.95 = 6650
    EXPECT_DOUBLE_EQ(applyDiscount(7000.0, false), 6650.0);
}

TEST(OrderCalcTest, ApplyDiscount_Path6_NoDiscount) {
    // Путь 6: (total < 0)=F, (>= 10000)=F, (>= 5000)=F
    EXPECT_DOUBLE_EQ(applyDiscount(1000.0, true), 1000.0);
}

// ====================================================================================================
// Тесты для функции calcShipping
// ====================================================================================================

TEST(OrderCalcTest, CalcShipping_Path1_NegativeTotal) {
    // Путь 1: Условие (total < 0) = True
    EXPECT_DOUBLE_EQ(calcShipping(-10.0), -1.0);
}

TEST(OrderCalcTest, CalcShipping_Path2_FreeShipping) {
    // Путь 2: (total < 0)=F, (total <= 5000)=True
    // Проверяем границу (5000)
    EXPECT_DOUBLE_EQ(calcShipping(5000.0), 0.0);
}

TEST(OrderCalcTest, CalcShipping_Path3_PaidShipping) {
    // Путь 3: (total < 0)=F, (total <= 5000)=False
    // Проверяем значение сразу за границей (5001)
    EXPECT_DOUBLE_EQ(calcShipping(5001.0), 300.0);
}

// ====================================================================================================
// Тесты для функции finalPrice
// ====================================================================================================

TEST(OrderCalcTest, FinalPrice_Path1_InvalidInput) {
    // Путь 1: Составное условие (total < 0 || discount < 0 || shipping < 0) = True
    EXPECT_DOUBLE_EQ(finalPrice(-10.0, 0.0, 0.0), -1.0);
}

TEST(OrderCalcTest, FinalPrice_Path2_ClampedToZero) {
    // Путь 2: Усл1=False, (result < 0) = True
    // 100 - 200 + 50 = -50 -> обнуляется до 0.0
    EXPECT_DOUBLE_EQ(finalPrice(100.0, 200.0, 50.0), 0.0);
}

TEST(OrderCalcTest, FinalPrice_Path3_NormalCalculation) {
    // Путь 3: Усл1=False, (result < 0) = False
    // 100 - 10 + 20.55 = 110.55
    EXPECT_DOUBLE_EQ(finalPrice(100.0, 10.0, 20.55), 110.55);
}

// ====================================================================================================
// Тесты для функции countExpensiveItems
// ====================================================================================================

TEST(OrderCalcTest, CountExpensiveItems_Path1_EmptyVector) {
    // Путь 1: 0 итераций цикла. Условие (i < size) = False
    std::vector<double> prices = {};
    EXPECT_EQ(countExpensiveItems(prices, 100.0), 0);
}

TEST(OrderCalcTest, CountExpensiveItems_Path2_OneItemBelowThreshold) {
    // Путь 2: 1 итерация. Условие цикла = True, Условие (price > threshold) = False
    std::vector<double> prices = {50.0};
    EXPECT_EQ(countExpensiveItems(prices, 100.0), 0);
}

TEST(OrderCalcTest, CountExpensiveItems_Path3_OneItemAboveThreshold) {
    // Путь 3: 1 итерация. Условие цикла = True, Условие (price > threshold) = True
    std::vector<double> prices = {150.0};
    EXPECT_EQ(countExpensiveItems(prices, 100.0), 1);
}

TEST(OrderCalcTest, CountExpensiveItems_Path4_MultipleIterations) {
    // Путь 4: >1 итераций. Проверяем обратное ребро графа (петлю цикла)
    std::vector<double> prices = {150.0, 50.0, 200.0};
    // 150 > 100 (count=1), 50 < 100 (count=1), 200 > 100 (count=2)
    EXPECT_EQ(countExpensiveItems(prices, 100.0), 2);
}

// ====================================================================================================
// Макросы EXPECT_TRUE / EXPECT_FALSE
// ====================================================================================================
TEST(OrderCalcTest, MacroChecks_TrueAndFalse) {
    // Проверяем, что доставка для дорогой покупки не равна нулю (макрос EXPECT_TRUE)
    EXPECT_TRUE(calcShipping(10000.0) > 0.0); 
    
    // Проверяем, что скидка не может быть больше самой суммы заказа (макрос EXPECT_FALSE)
    double discountAmount = 15000.0 - applyDiscount(15000.0, true);
    EXPECT_FALSE(discountAmount > 15000.0); 
}

// ====================================================================================================
// Падающий тест, потому что ачепятка о бесплатной доставке: 
// Комментарий говорит о скидке при доставке на цену от 5000, но код говорит, что при цене не выше 5000
// ====================================================================================================
TEST(OrderCalcTest, CalcShipping_BugDemonstration_FAIL) {
    EXPECT_DOUBLE_EQ(calcShipping(6000.0), 0.0); 
}
