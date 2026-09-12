#include <gtest/gtest.h>
#include "order_calc.h"

// =========================================================================
// Тесты для productOddIndices
// =========================================================================

TEST(VariantTest, ProductOddIndices_EmptyOrTooSmall) {
    EXPECT_DOUBLE_EQ(productOddIndices({}), 1.0);
    EXPECT_DOUBLE_EQ(productOddIndices({10.0}), 1.0);
}

TEST(VariantTest, ProductOddIndices_OneIteration) {
    EXPECT_DOUBLE_EQ(productOddIndices({10.0, 5.0}), 5.0);
}

TEST(VariantTest, ProductOddIndices_MultipleIterations) {
    EXPECT_DOUBLE_EQ(productOddIndices({1.0, 2.0, 3.0, 4.0}), 8.0);
}


// =========================================================================
// Тесты для sumOddBelowMainDiagonal
// =========================================================================

TEST(VariantTest, SumOddBelowDiag_EmptyMatrix) {
    std::vector<std::vector<int>> A = {};
    EXPECT_EQ(sumOddBelowMainDiagonal(A), 0);
}

TEST(VariantTest, SumOddBelowDiag_1x1Matrix) {
    std::vector<std::vector<int>> A = {{5}};
    EXPECT_EQ(sumOddBelowMainDiagonal(A), 0);
}

TEST(VariantTest, SumOddBelowDiag_2x2_EvenBelow) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {4, 5}
    };
    EXPECT_EQ(sumOddBelowMainDiagonal(A), 0);
}

TEST(VariantTest, SumOddBelowDiag_2x2_OddBelow) {
    std::vector<std::vector<int>> A = {
        {1, 2},
        {3, 5}
    };
    EXPECT_EQ(sumOddBelowMainDiagonal(A), 3);
}

TEST(VariantTest, SumOddBelowDiag_3x3_LoopBackEdges) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    EXPECT_EQ(sumOddBelowMainDiagonal(A), 7);
}


// =========================================================================
// Тесты для rotatePricesRight
// =========================================================================

TEST(RotatePricesRightTest, EmptyVector) {
    // T1: Пустой вектор -> не изменяется
    std::vector<double> prices = {};
    rotatePricesRight(prices, 5);
    EXPECT_TRUE(prices.empty());
}

TEST(RotatePricesRightTest, NegativeShift) {
    // T2: Отрицательный сдвиг -> не изменяется
    std::vector<double> prices = {1.0, 2.0, 3.0};
    rotatePricesRight(prices, -1);
    std::vector<double> expected = {1.0, 2.0, 3.0};
    EXPECT_EQ(prices, expected);
}

TEST(RotatePricesRightTest, ZeroShift) {
    // T3: Нулевой сдвиг -> не изменяется
    std::vector<double> prices = {1.0, 2.0, 3.0};
    rotatePricesRight(prices, 0);
    std::vector<double> expected = {1.0, 2.0, 3.0};
    EXPECT_EQ(prices, expected);
}

TEST(RotatePricesRightTest, ShiftMultipleOfSize) {
    // T4: Сдвиг кратен размеру -> не изменяется (k == 0)
    std::vector<double> prices = {1.0, 2.0, 3.0};
    rotatePricesRight(prices, 3);
    std::vector<double> expected = {1.0, 2.0, 3.0};
    EXPECT_EQ(prices, expected);
}

TEST(RotatePricesRightTest, TwoElementsShiftOne) {
    // T5: Два элемента, сдвиг на 1 -> первые два цикла не выполняются
    std::vector<double> prices = {1.0, 2.0};
    rotatePricesRight(prices, 1);
    std::vector<double> expected = {2.0, 1.0};
    EXPECT_EQ(prices, expected);
}

TEST(RotatePricesRightTest, ThreeElementsShiftOne) {
    // T6: Три элемента, сдвиг на 1
    std::vector<double> prices = {1.0, 2.0, 3.0};
    rotatePricesRight(prices, 1);
    std::vector<double> expected = {3.0, 1.0, 2.0};
    EXPECT_EQ(prices, expected);
}

TEST(RotatePricesRightTest, FiveElementsShiftTwo) {
    // T7: Полный случай - несколько итераций во всех трёх циклах
    std::vector<double> prices = {1.0, 2.0, 3.0, 4.0, 5.0};
    rotatePricesRight(prices, 2);
    std::vector<double> expected = {4.0, 5.0, 1.0, 2.0, 3.0};
    EXPECT_EQ(prices, expected);
}

// =========================================================================
// Тесты для productOddIndexSum
// =========================================================================

TEST(ProductOddIndexSumTest, EmptyMatrix) {
    // T1: Пустая матрица -> 1.0
    std::vector<std::vector<double>> A = {};
    EXPECT_DOUBLE_EQ(productOddIndexSum(A), 1.0);
}

TEST(ProductOddIndexSumTest, OneByOneMatrix) {
    // T2: Матрица 1x1 -> условие (i+j)%2 != 0 ложно -> 1.0
    std::vector<std::vector<double>> A = {{5.0}};
    EXPECT_DOUBLE_EQ(productOddIndexSum(A), 1.0);
}

TEST(ProductOddIndexSumTest, OneByTwoMatrix) {
    // T3: Матрица 1x2 -> элемент [0][1] с нечётной суммой -> 3.0
    std::vector<std::vector<double>> A = {{2.0, 3.0}};
    EXPECT_DOUBLE_EQ(productOddIndexSum(A), 3.0);
}

TEST(ProductOddIndexSumTest, TwoByTwoMatrix) {
    // T4: Матрица 2x2 -> элементы [0][1]=2 и [1][0]=3 -> 6.0
    std::vector<std::vector<double>> A = {{1.0, 2.0}, {3.0, 4.0}};
    EXPECT_DOUBLE_EQ(productOddIndexSum(A), 6.0);
}

TEST(ProductOddIndexSumTest, ThreeByThreeMatrix) {
    // T5: Матрица 3x3 -> покрываем петли обоих циклов
    // Элементы с нечётной суммой индексов: [0][1]=2, [1][0]=4, [1][2]=6, [2][1]=8
    // Произведение: 2 * 4 * 6 * 8 = 384
    std::vector<std::vector<double>> A = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0}
    };
    EXPECT_DOUBLE_EQ(productOddIndexSum(A), 384.0);
}

//=========================================================================
// EXPECT_TRUE / EXPECT_FALSE
//=========================================================================

TEST(VariantMacroChecksTest, TrueAndFalseMacros) {
    // EXPECT_TRUE: после сдвига первый элемент изменился
    std::vector<double> prices = {1.0, 2.0, 3.0};
    rotatePricesRight(prices, 1);
    EXPECT_TRUE(prices[0] != 1.0);

    // EXPECT_FALSE: произведение в пустой матрице не больше 1
    std::vector<std::vector<double>> empty = {};
    EXPECT_FALSE(productOddIndexSum(empty) > 1.0);
}

