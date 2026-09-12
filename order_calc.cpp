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
    } else {                  // 5<-
      return total * 0.85;    // 7
    }
  } else if (total >= 5000) { // 8
    if (isPremium) {          // 9
      return total * 0.90;    // 10
    } else {                  // 9<-
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
  if (total <= 5000)    // 4
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