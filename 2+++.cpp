#include <iostream>
#include <cmath>       // Для sqrt()
#include <cstdlib>     // Для abort()
#include <limits>      // Для проверки ввода

using namespace std;

/**
 * @brief Считывает значение с клавиатуры с проверкой ввода
 * @return Введенное значение
 */
double getValue();

/**
 * @brief Вычисляет площадь прямоугольника
 */
double getRectangleArea(double a, double b);

/**
 * @brief Вычисляет площадь треугольника по формуле Герона
 */
double getTriangleArea(double a, double b, double c);

/**
 * @brief Проверяет существование треугольника
 */
void checkTriangleExist(double a, double b, double c);

/**
 * @brief Проверяет, что стороны прямоугольника положительные
 */
void checkRectangleSides(double length, double width);

/**
 * @brief Проверяет, что стороны треугольника положительные
 */
void checkTriangleSides(double a, double b, double c);

int main()
{
    cout << "Enter the length of the rectangle: ";
    double length = getValue();
    cout << "Enter the width of the rectangle: ";
    double width = getValue();
    checkRectangleSides(length, width);
    cout << "Area of the rectangle is: " << getRectangleArea(length, width) << endl;

    cout << "Enter the first side of the triangle: ";
    double a = getValue();
    cout << "Enter the second side of the triangle: ";
    double b = getValue();
    cout << "Enter the third side of the triangle: ";
    double c = getValue();
    checkTriangleSides(a, b, c);
    checkTriangleExist(a, b, c);

    cout << "Area of the triangle is: " << getTriangleArea(a, b, c) << endl;

    return 0;
}

double getValue()
{
    double value;
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect value entered." << endl;
        abort();
    }
    return value;
}

double getRectangleArea(double a, double b)
{
    return a * b;
}

double getTriangleArea(double a, double b, double c)
{
    double p = (a + b + c) / 2.0; // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Формула Герона
}

void checkTriangleExist(double a, double b, double c)
{
    if (a + b <= c, a+c<=b, b+c<=a){
        cout << "Triangle does not exist with the given sides." << endl;
        abort();
    }
}

void checkTriangleSides(double a, double b, double c)
{
    if (a <= 0, b<= 0, c<=0) {
        cout << "Triangle sides must be positive numbers." << endl;
        abort();
    }
}

void checkRectangleSides(double length, double width)
{
    if (length <= 0 || width <= 0) {
        cout << "Rectangle sides must be positive numbers." << endl;
        abort();
    }
}