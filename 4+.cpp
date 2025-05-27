#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * @brief Считывает целое значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
int getValue();

/**
 * @brief Считывает вещественное значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getDouble();

/**
 * @brief Проверяет, что введенное значение n >= 1
 * @param n считанное значение
 */
void checkN(const int n);

/**
 * @brief Проверяет, что e > 0
 * @param e считанное значение
 */
void checkE(const double e);

/**
 * @brief Вычисляет факториал числа k (итеративно)
 * @param k число
 * @return k!
 */
double sumN(const int n);

/**
 * @brief Вычисляет сумму членов ряда, по модулю не меньших e
 * @param e точность
 * @return сумма
 */
double sumE(const double e);
/**@brief точка входа в программу
 * @return 0
 */
int main() {
    cout << "Введите количество членов ряда (n >= 1): ";
    int n = getValue();
    checkN(n);

    double sum_n = sumN(n);
    cout << "Сумма первых " << n << " членов ряда: " << fixed << setprecision(8) << sum_n << endl;

    cout << "Введите точность e (> 0): ";
    double e = getDouble();
    checkE(e);

    double sum_e = sumE(e);
    cout << "Сумма членов ряда с точностью " << e << ": " << fixed << setprecision(8) << sum_e << endl;

    return 0;
}

int getValue() {
    int value=0;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка ввода! Ожидалось целое число." << endl;
        exit(1);
    }
    return value;
}

double getDouble() {
    double value=0;
    cin >> value;
    if (cin.fail()) {
        cerr << "Ошибка ввода! Ожидалось число с плавающей точкой." << endl;
        exit(1);
    }
    return value;
}

void checkN(const int n) {
    if (n < 1) {
        cerr << "Ошибка: n должно быть >= 1!" << endl;
        exit(1);
    }
}

void checkE(const double e) {
    if (e <= 0) {
        cerr << "Ошибка: e должно быть > 0!" << endl;
        exit(1);
    }
}
double sumN(const int n) {
    double sum = 0.0;
    double term = 0.0; 
    for (int k = 1; k <= n; ++k) {
        term = (k == 1) ? 1 : (-1.0 / k) * term; 
        sum += term;
    }
    return sum;
}

double sumE(const double e) {
    double sum = 0.0;
    double term = 0.0; 
    int k = 1;
    while (fabs(term) > e) {
        term = (k == 1) ? 1 : (-1.0 / k) * term; 
        sum += term;
        k++;
    }
    return sum;
}