#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

/**
 * @brief оператор выбора способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY = 1 ручное заполнение
 */
enum SELECT
{
  RANDOM = 0,
  MANUALLY = 1
};

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Возвращает размер массива
 * @return Размер массива
 */
size_t get_size_arr();

/**
 * @brief Проверяет размер массива
 * @param n Размер массива
 */
void check_arr_n(const int n);

/**
 * @brief Проверяет диапазон
 * @param min Минимальное значение диапазона значений элементов массива
 * @param max Максимальное значение диапазона значений элементов массива
 */
void check_range(const int min, const int max);

/**
 * @brief Заполнение массива автоматически случайными числами в заданном диапазоне
 * @param arr Массив
 * @param n Размер массива
 * @param min Минимальное значение диапазона значений элементов массива
 * @param max Максимальное значение диапазона значений элементов массива
 */
void fill_arr_random(int *arr, const int n, const int min, const int max);

/**
 * @brief Заполнение массива вручную
 * @param arr Массив
 * @param n -Размер массива
 * @param min Минимальное значение диапазона значений элементов массива
 * @param max Максимальное значение диапазона значений элементов массива
 */
void fill_arr(int *arr, const int n, const int min, const int max);

/**
 * @brief Выводит массив на экран
 * @param arr Массив
 * @param n Размер массива
 */
void print_arr(const int *arr, const int n);

/**
 * @brief Выводит сумму отрицательных элементов массива
 * @param arr Указатель на массив целых чисел
 * @param n Размер массива
 */
void print_sum_of_negative_elements(const int *arr, const int n);

/**
 * @brief Выводит количество элементов, значения которых положительны и не превосходят заданного числа A
 * @param arr Указатель на массив
 * @param n Размер массива
 * @param a Заданное число A
 */
void print_count_positive_less_than_a(const int *arr, const int n, const int a);

/**
 * @brief Выводит номер последней пары соседних элементов с разными знаками
 * @param arr Указатель на массив
 * @param n Размер массива
 */
void print_last_pair_with_different_signs(const int *arr, const int n);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */
int main()
{
  setlocale(LC_ALL, "Russian");
  int n = get_size_arr();
  int *arr = new int[n];

  cout << "Введите минимальное и максимальное значение интервала: ";
  int minValue = get_value();
  int maxValue = get_value();
  check_range(minValue, maxValue);

  cout << "Введите выбор для заполнения массива: " << endl
       << RANDOM << " Для случайного заполнения" << endl
       << MANUALLY << " Для ручного заполнения" << endl;

  int choice = get_value();

  switch ((enum SELECT)choice)
  {
  case RANDOM:
    fill_arr_random(arr, n, minValue, maxValue);
    break;
  case MANUALLY:
    fill_arr(arr, n, minValue, maxValue);
    break;
  default:
    cout << "Ваш выбор неверен" << endl;
    delete[] arr;
    return 0;
  }

  cout << "Элементы массива:" << endl;
  print_arr(arr, n);

  print_sum_of_negative_elements(arr, n);
  cout << "Введите число A: ";
  int a = get_value();
  print_count_positive_less_than_a(arr, n, a);
  print_last_pair_with_different_signs(arr, n);

  delete[] arr;

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

size_t get_size_arr()
{
  cout << "Введите размер массива: ";
  int n = get_value();
  check_arr_n(n);
  return (size_t)n;
}

void check_arr_n(const int n)
{
  if (n <= 0)
  {
    cout << "Неправильный размер массива" << endl;
    abort();
  }
}

void check_range(const int min, const int max)
{
  if (min > max)
  {
    cout << "Введен неправильный интервал" << endl;
    abort();
  }
}

void fill_arr_random(int *arr, const int n, const int min, const int max)
{
  srand(time(0));
  for (size_t i = 0; i < n; i++)
  {
    arr[i] = rand() % (max - min) + min;
  }
}

void fill_arr(int *arr, const int n, const int min, const int max)
{
  for (size_t i = 0; i < n;)
  {
    cout << "Введите значение для arr[" << i << "] (диапазон [" << min << ".." << max << "]): ";
    int value = get_value();

    if (value >= min && value <= max)
    {
      arr[i] = value;
      i++;
    }
    else
    {
      abort();
    }
  }
}

void print_arr(const int *arr, const int n)
{
  for (size_t i = 0; i < n; i++)
  {
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }
}

void print_sum_of_negative_elements(const int *arr, const int n)
{
  double sum = 0.0;

  for (size_t i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      sum += arr[i];
    }
  }

  cout << "Сумма отрицательных элементов: " << sum << endl;
}

void print_count_positive_less_than_a(const int *arr, const int n, const int a)
{
  int count = 0;
  for (size_t i = 0; i < n; i++)
  {
    if (arr[i] > 0 && arr[i] <= a)
    {
      count++;
    }
  }

  if (count == 0)
  {
    cout << "В массиве нет положительных элементов, не превосходящих " << a << "." << endl;
  }
  else
  {
    cout << "Количество положительных элементов, не превосходящих " << a << ": " << count << endl;
  }
}

void print_last_pair_with_different_signs(const int *arr, const int n)
{
  int last_pair_index = -1;

  for (size_t i = 0; i < n - 1; i++)
  {
    if ((arr[i] > 0 && arr[i + 1] < 0) ||
        (arr[i] < 0 && arr[i + 1] > 0))
    {
      last_pair_index = i;
    }
  }

  if (last_pair_index == -1)
  {
    cout << "В массиве нет пар соседних элементов с разными знаками." << endl;
  }
  else
  {
    cout << "Номер последней пары с разными знаками: " << last_pair_index << endl;
    cout << "Элементы пары: " << arr[last_pair_index] << " и " << arr[last_pair_index + 1] << endl;
  }
}
