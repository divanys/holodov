//
// Created by divan on 9/12/23.
//
// найти max and min элементы массива

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
    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    cout << "max "  << max;
    cout << endl;
    cout << "min "  << min;
    return 0;
}
