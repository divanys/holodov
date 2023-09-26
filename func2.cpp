//
// Created by divan on 9/26/23.
//
// 2 массива с разными размерами
// написать функцию, которая заполняет их элементы значениями и выводит. принимает: массив и размер
#include <iostream>

using namespace std;

long double fact(int a) {
    if (a < 0)
        return 0;
    else if (a == 0)
        return 1;
    else
        return a * fact(a - 1);
}

