//
// Created by divan on 9/25/23.
//
//3. Сумма цифр натурального числа.
//Дано натуральное число N. Напишите программу, вычисляющую сумму цифр числа N. (с использованием while)

#include <iostream>
using namespace std;

int main() {
    cout << "Введите натуральное целое число N" << endl;
    int n, sum = 0, digit;
    cin >> n;
    int cons = n;
    while (n > 0) {
        digit = n % 10;
        sum += digit;
        n = n / 10;
    }
    cout << "Сумма цифр числа " << cons << " равна " << sum;
}