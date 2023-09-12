//
// Created by divan on 9/12/23.
//
// найти сумму отрицательных элементов массива

#include <iostream>
using namespace std;

int main() {
    int n, sum = 1;
    cout << "Размер массива" << endl;
    cin >> n;
    int arr[n] = {};
    for (int i = 0; i < n; i++) {
        cout << "введите " << i + 1 << " элемент ";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            sum *= arr[i];
        }
    }
    cout << "произведение "  << sum;
    return 0;
}
