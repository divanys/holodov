//
// Created by divan on 9/26/23.
//
#include <iostream>

using namespace std;
long double fact(int a);

int main() {
    int n;
    cout << "Введите число для вычисления факториала" << endl;
    cin >> n;
    cout << "Факториал числа " << n << " = " << fact(n) << endl;
    return 0;
}

long double fact(int a) {
    if (a < 0)
        return 0;
    else if (a == 0)
        return 1;
    else
        return a * fact(a - 1);
}