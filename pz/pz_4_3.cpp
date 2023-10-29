//
// Created by divan on 10/27/23.
//
// Создать динамические массивы, используя указатели. Дан массив p(n).
// Каждый положительный элемент в нем возвести в квадрат. Остальные элементы оставить прежними.

#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
        if (p[i] > 0) {
            p[i] = p[i] * p[i];
        }
    }

    cout << "Измененный массив: ";
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;

    return 0;
}
