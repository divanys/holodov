//
// Created by divan on 11/11/23.
//
// объявить класс радиус, содержащий величину радиуса некоторой геом фигуры, в классе объявить
// одну скрытую переменную радиус,
// методы гет и сет для переменной радиус
// 2 внешние дружественные функции: гетленгхт и гетэррей (площадь)
// 1 друж класс value
// в value объявляется внешний метод гетвалуе возвр объект шара заданного радиуса

#include <iostream>

class Radius {
private:
    double radius;

public:
    Radius() : radius(0.0) {}

    // Геттер для получения значения радиуса
    double getRadius() const {
        return radius;
    }

    // Сеттер для установки значения радиуса
    void setRadius(double newRadius) {
        radius = newRadius;
    }

    // Дружественная функция для получения длины окружности
    friend double getLength(const Radius &r);

    // Дружественная функция для получения площади круга
    friend double getArea(const Radius &r);

    // Дружественный класс
    friend class Value;
};

// Дружественный класс
class Value {
public:
    // Внешний метод для получения значения объекта шара
    static double getValue(const Radius &r) {
        // Просто возвращаем значение радиуса
        return r.radius;
    }
};

// Внешняя функция для получения длины окружности
double getLength(const Radius &r) {
    return 2 * 3.14159265358979323846 * r.radius;
}

// Внешняя функция для получения площади круга
double getArea(const Radius &r) {
    return 3.1415 * r.radius * r.radius;
}

int main() {
    Radius circle;
    circle.setRadius(5.0);

    std::cout << "Radius: " << circle.getRadius() << std::endl;
    std::cout << "Length: " << getLength(circle) << std::endl;
    std::cout << "Area: " << getArea(circle) << std::endl;

    // Использование дружественного класса
    std::cout << "Value: " << Value::getValue(circle) << std::endl;

    return 0;
}
