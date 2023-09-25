//
// Created by divan on 9/25/23.
//
//4. Опять сумма.
//Напишите программу для поиска суммы чисел.
//Вводится 2 целых числа a и b (a <= b). Необходимо вычислить сумму всех чисел от a до b включительно.

#include <iostream>

using namespace std;

int main() {
    int a, b, sum = 0, i;
    cout << "Введите число a" << endl;
    cin >> a;
    cout << "Введите число b" << endl;
    cin >> b;
    if (a <= b) {
        i = a;
        while (i != (b + 1)) {
            sum += i;
            i++;
        }
    } else cout << "Число a больше числа b!";

    cout << "Сумма всех чисел от " << a << " до " << b << " равна " << sum << endl;
}