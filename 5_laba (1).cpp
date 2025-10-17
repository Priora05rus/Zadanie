#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief Считывает значения с клавиатуры с проверкой ввода
 * @return Возвращает значение, если оно правильное, иначе завершает программу
 */
double get_value();

/**
 * @brief Рекурсивно вычисляет факториал числа
 * @param k число, факториал которого требуется вычислить
 * @return k!
 */
double factorial(int k);

/**
 * @brief Рекурсивно вычисляет сумму первых n членов ряда
 * S = Σ ((-1)^k * k / k!),  k = 0..n
 * @param k текущий индекс
 * @param n максимальный индекс
 * @param sum накопленная сумма
 */
double calculate_first_n_series_sum_recursive(const int k, const int n, const double sum);

/**
 * @brief Рекурсивно вычисляет сумму членов ряда,
 * по модулю не меньших заданного числа eps
 * @param k текущий индекс
 * @param eps точность
 * @param sum накопленная сумма
 */
double calculate_series_sum_above_epsilon_recursive(const int k, const double eps, const double sum);

/**
 * @brief Точка входа в программу
 */
int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Сумма первых n членов ряда" << endl;
    cout << "Введите n (n ≥ 0): ";
    int n = static_cast<int>(get_value());

    cout << "Сумма первых " << n << " членов ряда: "
         << calculate_first_n_series_sum_recursive(0, n, 0.0) << endl;

    cout << "Сумма членов ряда, не меньших по модулю ε" << endl;
    cout << "Введите ε (ε > 0): ";
    double eps = get_value();

    cout << "Сумма членов ряда, не меньших по модулю " << eps << ": "
         << calculate_series_sum_above_epsilon_recursive(0, eps, 0.0) << endl;

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
    if (value < 0)
    {
        cout << "Значение должно быть неотрицательным" << endl;
        abort();
    }
    return value;
}

double factorial(int k)
{
    if (k == 0 || k == 1)
        return 1.0;
    return k * factorial(k - 1);
}

double calculate_first_n_series_sum_recursive(const int k, const int n, const double sum)
{
    if (k > n)
        return sum;

    double term = (k == 0) ? 0.0 : pow(-1, k) * k / factorial(k);

    return calculate_first_n_series_sum_recursive(k + 1, n, sum + term);
}

double calculate_series_sum_above_epsilon_recursive(const int k, const double eps, const double sum)
{
    double term = (k == 0) ? 0.0 : pow(-1, k) * k / factorial(k);

    if (fabs(term) < eps)
        return sum;

    return calculate_series_sum_above_epsilon_recursive(k + 1, eps, sum + term);
}
