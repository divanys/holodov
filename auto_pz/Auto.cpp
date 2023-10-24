//
// Created by divan on 10/24/23.
//

#include "Auto.h"

Car::Car() {
    brand = "";
    model = "";
    licensePlate = "";
    year = 0;
    price = 0.0;
}

void Car::inputInfo() {
    std::cout << "Введите марку автомобиля: ";
    std::cin >> brand;
    std::cout << "Введите модель автомобиля: ";
    std::cin >> model;
    std::cout << "Введите государственный номер: ";
    std::cin >> licensePlate;
    std::cout << "Введите год выпуска: ";
    std::cin >> year;
    std::cout << "Введите цену: ";
    std::cin >> price;
}

void Car::displayInfo() {
    std::cout << "Марка: " << brand << std::endl;
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Гос. номер: " << licensePlate << std::endl;
    std::cout << "Год выпуска: " << year << std::endl;
    std::cout << "Цена: " << price << std::endl;
}

void Car::saveToFile(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Марка: " << brand << std::endl;
        file << "Модель: " << model << std::endl;
        file << "Гос. номер: " << licensePlate << std::endl;
        file << "Год выпуска: " << year << std::endl;
        file << "Цена: " << price << std::endl;
        file.close();
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

Car Car::findMostExpensiveCar(Car *cars, int numCars) {
    if (numCars <= 0) {
        return Car();
    }

    Car mostExpensiveCar = cars[0];

    for (int i = 1; i < numCars; i++) {
        if (cars[i].price > mostExpensiveCar.price) {
            mostExpensiveCar = cars[i];
        }
    }

    return mostExpensiveCar;
}

Car::~Car() {
    std::cout << std::endl;
}
