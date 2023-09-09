//
// Created by divan on 9/6/23.
//
// реализовать треугольник паскаля

#include <iostream>
using namespace std;

int main() {
    int numRows;

    cout << "Введите количество строк треугольника Паскаля: ";
    cin >> numRows;

    for (int i = 0; i < numRows; i++) {
        int coeff = 1;
        for (int j = 0; j <= i; j++) {
            cout << coeff << " ";
            coeff = coeff * (i - j) / (j + 1);
        }
        cout << endl;
    }

    return 0;
}
