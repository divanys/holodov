// Получить практические навыки разработки программ на языке С++ с использованием динамических одномерных и двумерных массивов.
// Created by divan on 10/27/23.
//
// Создать динамические массивы, используя указатели.
// Дан двумерный массивa, размером (n⋅m). Найти минимальный элемент в каждой строке матрицы среди положительных элементов.
#include <iostream>
#include <climits>

using namespace std;

int **create2DArray(int rows, int cols) {
    int **array = new int *[rows];

    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    return array;
}

int findMin(int *row, int cols) {
    int minElement = INT_MAX;

    for (int j = 0; j < cols; j++) {
        if (row[j] > 0 && row[j] < minElement) {
            minElement = row[j];
        }
    }

    return minElement;
}

int main() {
    int n, m;

    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    int **matrix = create2DArray(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cout << "Введите элемент " << i << "," << j << ": ";
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        int minElement = findMin(matrix[i], m);

        if (minElement == INT_MAX) {
            cout << "В строке " << i << " нет положительных элементов" << endl;
        } else {
            cout << "Минимальный положительный элемент в строке " << i << " : " << minElement << endl;
        }    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
