#include <iostream>
#include <cmath>
#include <limits>
using namespace std;
/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Функция для вычисления значения функции
 * @param x Значение x
 * @return Вычисленное значение или 0
 */
double calculate_expression(const double x);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "Введите интервал: ";
  double start = get_value();
  double end = get_value();

  cout << "Введите шаг: ";
  double step = get_value();

  if (start >= end || step <= 0)
  {
    cout << "Некорректные параметры интервала или шага" << endl;
    abort();
  }

  cout << "\nТаблица значений функции на интервале [" << start << ", " << end << "] с шагом " << step << ":" << endl;
  cout << "======================================================" << endl;
  cout << "    x    |    y" << endl;
  cout << "---------|---------" << endl;

  for (double x = start; x < end + step; x += step)
  {
    double y = calculate_expression(x);

    cout.precision(4);
    cout << fixed;

    if (y == 0)
    {
      cout << x << " | Отсутствует решение" << endl;
    }
    else
    {
      cout << x << " | " << y << endl;
    }
  }

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
  return value;
}

double calculate_expression(const double x)
{
  double denominator = 3 + sin(3.6 * x);

  if (fabs(denominator) < std::numeric_limits<double>::epsilon())
  {
    return 0;
  }

  return x - 1 / denominator;
}
