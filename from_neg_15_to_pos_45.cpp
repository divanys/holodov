//
// Created by divan on 9/26/23.
//

// дз
// 2мерный массиыв, размер - с клавиатуры
// заполнить функцией (массив, размер а, размер б)
// от -15 до 45 включительно
// написать 5 доп функции:
// 1. сумма кажой строки
// 2. сумма каждого столбца
// 3. произведение по главной диагонали
// 4. среднееарифм по побочной
// 5. вывод


#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;

void fillMass(int arr[MAX_SIZE][MAX_SIZE], int a, int b) {
    srand(time(NULL));
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            arr[i][j] = rand() % 61 - 15; // Генерация случайных чисел от -15 до 45
        }
    }
}

int sumRow(int arr[MAX_SIZE][MAX_SIZE], int a, int b, int row) {
    int sum = 0;
    for(int j = 0; j < b; j++) {
        sum += arr[row][j];
    }
    return sum;
}

int sumColumn(int arr[MAX_SIZE][MAX_SIZE], int a, int b, int col) {
    int sum = 0;
    for(int i = 0; i < a; i++) {
        sum += arr[i][col];
    }
    return sum;
}

int productMainDiagonal(int arr[MAX_SIZE][MAX_SIZE], int a, int b) {
    int product = 1;
    for(int i = 0; i < min(a, b); i++) {
        product *= arr[i][i];
    }
    return product;
}

double avgSecondaryDiagonal(int arr[MAX_SIZE][MAX_SIZE], int a, int b) {
    double sum = 0;
    for(int i = 0; i < a; i++) {
        sum += arr[i][b - i - 1];
    }
    return sum / a;
}

void printMass(int arr[MAX_SIZE][MAX_SIZE], int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a, b;
    cout << "Введите размеры массива (a b): ";
    cin >> a >> b;

    if(a <= 0 || b <= 0 || a > MAX_SIZE || b > MAX_SIZE) {
        cout << "Неверные размеры массива." << endl;
        return 1;
    }

    int arr[MAX_SIZE][MAX_SIZE];

    fillMass(arr, a, b);

    cout << "Массив:" << endl;
    printMass(arr, a, b);

    cout << "Суммы строк:" << endl;
    for(int i = 0; i < a; i++) {
        cout << "Строка " << i + 1 << ": " << sumRow(arr, a, b, i) << endl;
    }

    cout << "Суммы столбцов:" << endl;
    for(int j = 0; j < b; j++) {
        cout << "Столбец " << j + 1 << ": " << sumColumn(arr, a, b, j) << endl;
    }

    if (a != b) {
        cout << "Матрица не квадратная. Действия по диагоналям недоступны." << endl;
        return 1;
    } else {
        cout << "Произведение по главной диагонали: " << productMainDiagonal(arr, a, b) << endl;
        cout << "Среднее арифметическое по побочной диагонали: " << avgSecondaryDiagonal(arr, a, b) << endl;
    }

    return 0;
}
