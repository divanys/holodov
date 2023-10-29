//
// Created by divan on 10/27/23.
//
// Создать динамические массивы, используя указатели. Дан двумерный массив a, размером (n⋅n)
// (или квадратная матрица a). Найти сумму номеров минимального и максимального элементов ее побочной диагонали.
#include <iostream>
#include <climits>

using namespace std;

int **create2DArray(int n) {
    int **array = new int *[n];

    for (int i = 0; i < n; i++) {
        array[i] = new int[n];
    }

    return array;
}

int findMin(int *arr, int n) {
    int minElement = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }

    return minElement;
}

int findMax(int *arr, int n) {
    int maxElement = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
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

    int *diagonal = new int[n];

    for (int i = 0; i < n; i++) {
        diagonal[i] = matrix[i][n - i - 1];
    }

    int minElement = findMin(diagonal, n);
    int maxElement = findMax(diagonal, n);

    cout << "Матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Минимальный элемент побочной диагонали: " << minElement << endl;
    cout << "Максимальный элемент побочной диагонали: " << maxElement << endl;
    cout << "Сумма номеров минимального и максимального элементов: " << (minElement + maxElement) << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] diagonal;

    return 0;
}
