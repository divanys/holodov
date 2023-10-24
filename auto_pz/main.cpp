//
// Created by divan on 10/24/23.
//
// Создать класс автомобиль
// Свойства
//  1. марка
//  2. модель
//  3. гос номер
//  4. год выпуска
//  5. цена

// Создать конструктор сделать все свойства приватными а методы публичными
// 1 метод ввод информации с клавиатуры
// 2 метод вывод информации на экран
// 3 метод записать информацию в файл
// Создать деструктор
// 4 метод выявить самый дорогой автомобиль и также записать его в файл
// Разделить по принципу ооп разработки

#include "Auto.h"
#include "Auto.cpp"

int main() {
    int numCars;

    std::cout << "Введите количество автомобилей: ";
    std::cin >> numCars;

    Car *cars = new Car[numCars];

    for (int i = 0; i < numCars; i++) {
        std::cout << "\nВведите информацию об автомобиле #" << i + 1 << std::endl;
        cars[i].inputInfo();
    }

    Car mostExpensiveCar = Car::findMostExpensiveCar(cars, numCars);

    std::cout << "\nСамый дорогой автомобиль:" << std::endl;
    mostExpensiveCar.displayInfo();

    mostExpensiveCar.saveToFile("./auto_pz/most_expensive_car.txt");

    delete[] cars;

    return 0;
}