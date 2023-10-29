//
// Created by divan on 10/27/23.
//
// Создать динамические массивы, используя указатели. Дан двумерный массив a,
// размером (n⋅n). Упорядочить по возрастанию первый столбец матрицы.

#include <iostream>

using namespace std;

int **create2DArray(int n) {
    int **array = new int *[n];

    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }

    return array;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    cout << "n = ";
    cin >> n;

    int **matrix = create2DArray(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cout << "Введите элемент " << i << "," << j << ": ";
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    cout << "Исходная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    int *firstColumn = new int[n];
    for (int i = 0; i < n; i++) {
        firstColumn[i] = matrix[i][0];
    }

    bubbleSort(firstColumn, n);

    for (int i = 0; i < n; i++) {
        matrix[i][0] = firstColumn[i];
    }

    cout << "Упорядоченная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
