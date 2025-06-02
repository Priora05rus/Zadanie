
#include <iostream>       // подключаем библиотеку для ввода-вывода
#include <cmath>          // для математических функций (например, sin, fabs)
#include <iomanip>        // для форматирования вывода (например, setprecision, setw)
#include <limits>         // для работы с пределами чисел (numeric_limits)

using namespace std;      // используем стандартное пространство имён

/// Функция вычисляет значение y по формуле y = x - 1 / (3 + sin(3.6x))
double func(double x) {
    double denominator = 3 + sin(3.6 * x); // вычисляем знаменатель выражения
    if (fabs(denominator) < numeric_limits<double>::epsilon()) { // проверка деления на 0
        cout << "Ошибка: деление на ноль при x = " << x << endl; // вывод сообщения об ошибке
        return numeric_limits<double>::quiet_NaN(); // возвращаем NaN (не число), чтобы избежать ошибки
    }
    return x - 1.0 / denominator; // вычисляем и возвращаем значение функции
}

int main() {
    double start, end, step; // переменные для начала, конца и шага интервала

    cout << "Введите начальное значение интервала x: "; // запрос начального значения
    cin >> start; // считываем начальное значение
    cout << "Введите конечное значение интервала x: "; // запрос конечного значения
    cin >> end; // считываем конечное значение
    cout << "Введите шаг изменения x: "; // запрос шага изменения
    cin >> step; // считываем шаг

    cout << fixed << setprecision(4); // устанавливаем формат вывода чисел: фиксированная точка, 4 знака после запятой
    cout << " x\t\t y" << endl; // заголовок таблицы
    cout << "------------------------" << endl; // разделительная линия

    // цикл от start до end с шагом step
    for (double x = start; x <= end + numeric_limits<double>::epsilon(); x += step) {
        double y = func(x); // вычисляем значение функции
        cout << setw(5) << x << "\t" << setw(10) << y << endl; // форматированный вывод x и y
    }

    return 0; // завершение программы
}
