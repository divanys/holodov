//
// Created by divan on 10/27/23.
//
// Определить комбинированный (структурный) тип, описывающий окружность и состоящий из двух полей: «радиус» и «центр».
// Поле «центр» в свою очередь состоит еще из двух полей: «координата Х» и «координата Y».
// Ввести информацию по 10 окружностям. Вывести координаты центра окружности, чей радиус самый маленький.

#include <iostream>
using namespace std;

// Структура, представляющая координату (X, Y)
struct Point {
    double x;
    double y;
};

// Структура, представляющая окружность
struct Circle {
    double radius;
    Point center;
};

int main() {
    const int numCircles = 3; // Количество окружностей
    Circle circles[numCircles];

    // Ввод информации о 10 окружностях
    for (int i = 0; i < numCircles; i++) {
        cout << "Введите радиус окружности " << i + 1 << ": ";
        cin >> circles[i].radius;

        cout << "Введите координату X центра окружности " << i + 1 << ": ";
        cin >> circles[i].center.x;

        cout << "Введите координату Y центра окружности " << i + 1 << ": ";
        cin >> circles[i].center.y;
    }

    // Найдем окружность с минимальным радиусом
    Circle minRadiusCircle = circles[0];

    for (int i = 1; i < numCircles; i++) {
        if (circles[i].radius < minRadiusCircle.radius) {
            minRadiusCircle = circles[i];
        }
    }

    // Вывод координат центра окружности с минимальным радиусом
    cout << "Координаты центра окружности с минимальным радиусом:" << endl;
    cout << "X: " << minRadiusCircle.center.x << endl;
    cout << "Y: " << minRadiusCircle.center.y << endl;

    return 0;
}
