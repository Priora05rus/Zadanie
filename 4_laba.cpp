#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <fstream>
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
 * @brief Функция для создания файла с данными для GNUplot
 * @param x_values Вектор значений x
 * @param y_values Вектор значений y
 */
void create_gnuplot_script(const vector<double> &x_values, const vector<double> &y_values);

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

  vector<double> x_values, y_values;

  for (double x = start; x < end + step; x += step)
  {
    double y = calculate_expression(x);

    if (y == 0)
    {
      cout << "x: " << x << endl;
      cout << "y: Отсутствует решение" << endl;
      cout << endl;
    }
    else
    {
      x_values.push_back(x);
      y_values.push_back(y);
    }
  }

  create_gnuplot_script(x_values, y_values);

  cout << "Данные для графика сохранены в файлы:" << endl;
  cout << "- function_data.txt - данные функции" << endl;
  cout << "- plot_script.plt - скрипт для GNUplot" << endl;

  int result = system("gnuplot plot_script.plt");

  if (result == 0)
  {
    cout << "✓ График успешно создан: function_plot.png" << endl;
  }
  else
  {
    cout << "✗ Ошибка при построении графика" << endl;
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

void create_gnuplot_script(const vector<double> &x_values, const vector<double> &y_values)
{
  ofstream data_file("function_data.txt");
  ofstream script_file("plot_script.plt");

  for (size_t i = 0; i < x_values.size(); i++)
  {
    data_file << x_values[i] << " " << y_values[i] << endl;
  }
  data_file.close();

  script_file << "set terminal png size 800,600" << endl;
  script_file << "set output 'function_plot.png'" << endl;
  script_file << "set title 'График функции y = x - 1/(3 + sin(3.6x))'" << endl;
  script_file << "set xlabel 'x'" << endl;
  script_file << "set ylabel 'y'" << endl;
  script_file << "set grid" << endl;
  script_file << "plot 'function_data.txt' with linespoints title 'Функция'" << endl;
  script_file << "pause -1" << endl;
  script_file.close();
}
