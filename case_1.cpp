//
// Created by divan on 9/12/23.
//
// объявить 3 массива; два от 10 до 30 случайными; в эл 3 массива суммы i-тые
#include <time.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Размер массива" << endl;
    srand(time(NULL));
    cin >> n;
    int arr1[n] = {};
    int arr2[n] = {};
    int arr3[n] = {};
    for (int i = 0; i < n; i++) {
        arr1[i] = 10 + rand() % 21;
        arr2[i] = 10 + rand() % 21;
    }
    for (int i = 0; i < n; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << arr3[i] << " ";
    }

    int sum = 0;
    int max = arr3[0];
    int min = arr3[0];
    for (int i = 0; i < n; i++) {
        if (arr3[i] > max) {
            max = arr3[i];
        }
        if (arr3[i] < min) {
            min = arr3[i];
        }
        sum += arr3[i];
    }

    cout << endl;
    double sr_arifm;
    sr_arifm = (double) sum / n;
    cout << "среднеарифм "  << sr_arifm << endl;
    cout << "max "  << max;
    cout << endl;
    cout << "min "  << min;
    return 0;
}
