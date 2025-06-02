#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
*@brief Расчитывает сумму N членов последовательности
*@param n количество членов последовательности
*@return возвращает значение суммы
*/
double sumFirstN(const int n);

/**
*@brief Вычисляет сумму членов последовательности, по модулю не меньших заданного числа e
*@param e пороговое значение
*@return возвращает значение суммы
*/
double sumModuloE(const double e);

/**
*@brief Вычисляет рекуррентное выражение
*@param k переменная
*@return -1.0 / (k + 1) / (k + 2)
*/
double recur(const int k);

/**
*@brief Функция для проверки ввода n
*@return возвращает n если введено правильно, в противном случае -1
*/
int getValidN();

/**
*@brief Функция для проверки ввода e
*@return возвращает e если введено правильно, в противном случае -1
*/
double getValidE();

/**
*@brief Точка входа в программу
*@return 0 при успешном завершении, 1 при ошибке
*/
int main()
{
    setlocale(LC_ALL, "Russian");

    int n = getValidN();
    if (n == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма первых " << n << " членов последовательности: " << sumFirstN(n) << endl;

    double e = getValidE();
    if (e == -1)
    {
        return 1; // Возвращаем код ошибки
    }

    cout << "Сумма всех членов последовательности, модуль которых не меньше " << e << ": " << sumModuloE(e) << endl;

    return 0;
}

// Функция для проверки корректности ввода значения n
int getValidN()
{
    int n;
    cout << "Введите значение n: ";
    cin >> n;

    if (cin.fail() || n <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: n должно быть положительным числом." << endl;
        return -1;
    }

    return n;
}

// Функция для проверки корректности ввода значения e
double getValidE()
{
    double e;
    cout << "Введите значение e: ";
    cin >> e;

    if (cin.fail() || e < numeric_limits<double>::epsilon())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка: e должно быть положительным числом." << endl;
        return -1;
    }

    return e;
}

// Функция для вычисления суммы первых n членов последовательности
double sumFirstN(const int n)
{
    const double a0 = 1.0;
    double current = a0;
    double sum = current;

    for (int k = 0; k < n - 1; ++k) // n-1 итераций, т.к. a0 уже учтён
    {
        current *= recur(k);
        sum += current;
    }

    return sum;
}

// Функция для вычисления суммы членов, модуль которых не меньше e
double sumModuloE(const double e)
{
    double sum = 0.0;
    double current = 1.0;
    int k = 0;

    while (abs(current) >= e)
    {
        sum += current;
        current *= recur(k++);
    }

    return sum;
}

// Рекуррентное выражение
double recur(const int k)
{
    return -1.0 / (k + 1) / (k + 2);
}