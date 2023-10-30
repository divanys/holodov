//
// Created by divan on 10/27/23.
//
// Определить комбинированный (структурный) тип, описывающий окружность и состоящий из двух полей: «радиус» и «центр».
// Поле «центр» в свою очередь состоит еще из двух полей: «координата Х» и «координата Y».
// Ввести информацию по 10 окружностям.
// Вывести радиус окружности, чей центр расположен ближе всего к оси OX (оси абсцисс).
// Затем вывести информацию, отсортированную по возрастанию радиуса окружности.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x;
    double y;
};

struct Circle {
    double radius;
    Point center;
};

double distanceToOX(const Circle &circle) {
    return abs(circle.center.y);
}

bool compareByRadius(const Circle &circle1, const Circle &circle2) {
    return circle1.radius < circle2.radius;
}

int main() {
    const int numCircles = 10;
    vector<Circle> circles(numCircles);

    for (int i = 0; i < numCircles; i++) {
        cout << "Введите радиус окружности " << i + 1 << ": ";
        cin >> circles[i].radius;

        cout << "Введите координату X центра окружности " << i + 1 << ": ";
        cin >> circles[i].center.x;

        cout << "Введите координату Y центра окружности " << i + 1 << ": ";
        cin >> circles[i].center.y;
    }

    double minDistance = distanceToOX(circles[0]);
    double closestRadius = circles[0].radius;

    for (int i = 1; i < numCircles; i++) {
        double distance = distanceToOX(circles[i]);
        if (distance < minDistance) {
            minDistance = distance;
            closestRadius = circles[i].radius;
        }
    }

    cout << "Радиус окружности, чей центр ближе всего к оси OX: " << closestRadius << endl;

    sort(circles.begin(), circles.end(), compareByRadius);

    cout << "Информация о окружностях, отсортированная по радиусу:" << endl;
    for (int i = 0; i < numCircles; i++) {
        cout << "Радиус: " << circles[i].radius << endl;
        cout << "Центр (X, Y): " << circles[i].center.x << ", " << circles[i].center.y << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}
