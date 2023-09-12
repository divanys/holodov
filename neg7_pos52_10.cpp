//
// Created by divan on 9/12/23.
//
// 2. создать целочисленный массив на 10 элементов. заполнить от -7 до 52 (ключительно). после перезаписать все элемены
// больше 10 на (x - 10) пока не останутся только единицы, а не десятки

#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
    int arr1[10] = {};
    for (int i = 0; i < 10; i++) {
        arr1[i] = -7 + rand() % 53;
    }

    cout << "Сгенерированный массив:\n";
    for (int i = 0; i < 10; ++i) {
        cout << arr1[i] << " ";
    }

    cout << endl << "Полученный массив:\n";
    for (int i = 0; i < 10; ++i) {
        for (; arr1[i] >= 10;) {
            arr1[i] -= 10;
        }
        cout << arr1[i] << " ";
    }
    return 0;
}
