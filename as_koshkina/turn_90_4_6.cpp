//
// Created by divan on 9/25/23.
//
// 6. Поворот на 90
// Вводятся 2 натуральных числа: n (кол-во строк) и m (кол-во столбцов). Затем вводится двумерный массив размером n *m.
// Поверните его на 90 градусов по часовой стрелке и выведите на экран (через пробел).
// Данные:
// Ввод:
// 3
// 4
// 1 2 3 8
// 4 6 7 8
// -5 6 3 4

#include <iostream>

using namespace std;

int main() {

    int n, m, digit;
    cout << "Введите количество строк массива (n)" << endl;
    cin >> n;
    cout << "Введите количество столбцов массива (m)" << endl;
    cin >> m;
    int matrix[n][m], revers_matrix[m][n];
    cout << "Теперь введите элементы в массив" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> digit;
            matrix[i][j] = digit;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            revers_matrix[j][n - i - 1] = matrix[i][j];
        }
    }

    cout << "Исходная матрица: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Перевёрнутая матрица: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << revers_matrix[i][j] << " ";
        }
        cout << endl;
    }
}