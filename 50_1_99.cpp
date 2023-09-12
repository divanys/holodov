//
// Created by divan on 9/12/23.
//
// 1. Заполнить массив из 50 элементов рандомными нечетными от 1 до 99 (включительно)

#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    srand(time(NULL));
    int arr[50] = {};
    for (int i = 0; i < 50; ++i) {
        arr[i] = (rand() % 50) * 2 + 1;
    }

    cout << "Сгенерированный массив:\n";
    for (int i = 0; i < 50; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
