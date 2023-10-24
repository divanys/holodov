//
// Created by divan on 10/24/23.
//



#ifndef AUTO_H
#define AUTO_H

#include <iostream>
#include <fstream>

class Car {
private:
    std::string brand;
    std::string model;
    std::string licensePlate;
    int year;
    double price;

public:
    Car();

    void inputInfo();

    void displayInfo();

    void saveToFile(const std::string &filename);

    static Car findMostExpensiveCar(Car *cars, int numCars);

    ~Car();
};

#endif
