#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Вычисляет сумму первых n членов ряда
 * @param n Количество членов ряда.
 * @return Сумма ряда
 */
double calculate_first_n_series_sum(const int n);

/**
 * @brief Вычисляет сумму всех членов ряда, по модулю не меньших заданного числа e
 * @param eps Заданная точность (положительное число).
 * @return Сумма членов ряда, удовлетворяющих условию
 */
double calculate_series_sum_above_epsilon(const double eps);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "Сумма первых n членов ряда" << endl;
  cout << "Введите количество элементов ряда (n > 0): ";
  int n = get_value();
  cout << "Сумма первых " << n << " членов ряда: " << calculate_first_n_series_sum(n) << endl;

  cout << "Сумма членов ряда, не меньших по модулю ε" << endl;
  cout << "Введите значение e (e > 0): ";
  double eps = get_value();
  cout << "Сумма членов ряда, не меньших по модулю " << eps << ": " << calculate_series_sum_above_epsilon(eps) << endl;

  return 0;
}

double get_value()
{
  double value = 0;
  cin >> value;
  if (cin.fail())
  {
    cout << "Некорректное значение" << endl;
    abort();
  }
  if (value <= 0)
  {
    cout << "Значение должно быть положительным" << endl;
    abort();
  }
  return value;
}

double calculate_first_n_series_sum(const int n)
{
  double sum = 0.0;

  for (int k = 0; k <= n; k++)
  {
    sum += (pow(-1, k) * k) / tgamma(k + 1);
  }

  return sum;
}

double calculate_series_sum_above_epsilon(const double eps)
{
  double sum = 0.0;
  double term = -1.0;
  int k = 1;

  while (fabs(term) >= eps)
  {
    sum += term;
    k++;
    term = (pow(-1, k) * k) / tgamma(k + 1);
  }

  return sum;
}
