//
// Created by divan on 9/26/23.
//
// от 30 до 60 включительно
// создать ещё 2 функции для вычисления большего и минимального объекта
#include <time.h>
#include <iostream>

using namespace std;
const int arraySize = 5; // Changed name from 'size' to 'arraySize'

void show(int arr[][arraySize], const int size) { // Changed 'size' to 'arraySize'
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arraySize; j++) { // Changed 'size' to 'arraySize'
            arr[i][j] = 30 + rand() % 31;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int min(int arr[][arraySize], const int size) { // Changed 'size' to 'arraySize'
    int min = arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arraySize; j++) { // Changed 'size' to 'arraySize'
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int max(int arr[][arraySize], const int size) { // Changed 'size' to 'arraySize'
    int max = arr[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arraySize; j++) { // Changed 'size' to 'arraySize'
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
        }
    }
    return max;
}
