#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Функция для вычисления значения площади прямоугольника
 * @param length Длина прямоугольника
 * @param width Ширина прямоугольника
 * @return Возвращает вычисленную площадь прямоугольника
 */
double calculate_rectangle_area(const double length, const double width);

/**
 * @brief Функция для вычисления значения площади треугольника
 * @param a Сторона треугольника a
 * @param b Сторона треугольника b
 * @param c Сторона треугольника c
 * @return Возвращает вычисленную площадь треугольника
 */
double calculate_triangle_area(const double a, const double b, const double c);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
  setlocale(LC_ALL, "Russian");

  cout << "Введите значения сторон прямоугольника: ";
  double rect_a = get_value();
  double rect_b = get_value();

  cout << "Введите значения сторон треугольника: ";
  double tri_a = get_value();
  double tri_b = get_value();
  double tri_c = get_value();

  cout << "Площадь прямоугольника равна: " << calculate_rectangle_area(rect_a, rect_b) << endl;
  cout << "Площадь треугольника равна: " << calculate_triangle_area(tri_a, tri_b, tri_c) << endl;

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

double calculate_rectangle_area(const double length, const double width)
{
  return length * width;
}

double calculate_triangle_area(const double a, const double b, const double c)
{
  double p = (a + b + c) / 2;
  return sqrt(p * (p - a) * (p - b) * (p - c));
}
