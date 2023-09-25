//
// Created by divan on 9/25/23.
//
// 1. Сумма цифр.
// Дано трехзначное число. Найдите сумму его цифр.

#include <iostream>
using namespace std;
int main() {
    cout << "Введите трёхзначное число" << endl;
    int n;
    cin >> n;
    cout << "Сумма цифр числа " << n << " равна " << (n / 100) + (n % 10) + ((n / 10) % 10);
}
