//
// Created by divan on 9/25/23.
//
// Размер массива пользователь вводит ручками. Заполняется случайно от -15 до 50.
// Посчитать сумму в каждой строке и в каждом столбце.
// Перезаписать в квадрат элементы, которые стоят на нечетных позициях, 5 степень - четные.
// Посчитать среднее арифметическое матрицы. Вывести новый массив.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cout << "Введите количество строк: ";
    cin >> n;
    cout << "Введите количество столбцов: ";
    cin >> m;

    srand(time(0));

    int matrix[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand() % 66 - 15;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int rowSum[n] = {0};
    int colSum[m] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((i + j) % 2 != 0) {
                matrix[i][j] = pow(matrix[i][j], 5);
            } else {
                matrix[i][j] = pow(matrix[i][j], 2);
            }
        }
    }

    cout << "\nИзмененная матрица:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    double sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += matrix[i][j];
        }
    }

    double average = sum / (n * m);

    cout << "\nСреднее арифметическое: " << average << endl;

    return 0;
}