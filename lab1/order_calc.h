#pragma once
#include <string>
#include <vector>
#include <cmath>
#include <utility>
double applyDiscount(double total, bool isPremium);
double calcShipping(double total);
double finalPrice(double total, double discount, double shipping);
int countExpensiveItems(const std::vector<double>& prices, double threshold);

// \|/ Новые функции
double productOddIndices(const std::vector<double>& prices);                    
int sumOddBelowMainDiagonal(const std::vector<std::vector<int>>& A);
void rotatePricesRight(std::vector<double>& prices, int shift);
double productOddIndexSum(const std::vector<std::vector<double>>& A);