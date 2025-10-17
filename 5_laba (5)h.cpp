#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Рекурсивно вычисляет сумму ряда из первых n членов
 * @param k Текущий индекс (начинается с 1)
 * @param n Максимальный индекс
 * @param sum Накопленная сумма
 * @param term Текущий член ряда
 */
double calculate_first_n_series_sum_recursive(const int k, const int n, const double sum, const double term);

/**
 * @brief Рекурсивно вычисляет сумму членов ряда, по модулю не меньших ε
 * @param k Текущий индекс
 * @param eps Точность (ε)
 * @param sum Накопленная сумма
 * @param term Текущий член ряда
 */
double calculate_series_sum_above_epsilon_recursive(const int k, const double eps, const double sum, const double term);

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Сумма первых n членов ряда" << endl;
    cout << "Введите количество элементов ряда (n > 0): ";
    int n = static_cast<int>(get_value());

    cout << "Сумма первых " << n << " членов ряда: "
         << calculate_first_n_series_sum_recursive(1, n, 0.0, -1.0) << endl;

    cout << "Сумма членов ряда, не меньших по модулю ε" << endl;
    cout << "Введите значение ε (ε > 0): ";
    double eps = get_value();

    cout << "Сумма членов ряда, не меньших по модулю " << eps << ": "
         << calculate_series_sum_above_epsilon_recursive(1, eps, 0.0, -1.0) << endl;

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

/**
 * @brief Каждый следующий член выражается через предыдущий:
 * a_{k+1} = -a_k * k / (k + 1)
 */
double calculate_first_n_series_sum_recursive(const int k, const int n, const double sum, const double term)
{
    if (k > n)
        return sum;

    double next_sum = sum + term;
    double next_term = -term */k*pow(k + 1,2);

    return calculate_first_n_series_sum_recursive(k + 1, n, next_sum, next_term);
}

double calculate_series_sum_above_epsilon_recursive(const int k, const double eps, const double sum, const double term)
{
    if (fabs(term) < eps)
        return sum;

    double next_sum = sum + term;
    double next_term = -term * / k * pow(k + 1, 2);

    return calculate_series_sum_above_epsilon_recursive(k + 1, eps, next_sum, next_term);
}
