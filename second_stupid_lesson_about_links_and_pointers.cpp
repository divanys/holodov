//
// Created by divan on 9/29/23.
//
// НОД

#include <iostream>

using namespace std;

int nod(int, int);
int main() {
    int(*prtnod)(int, int);  // объявляем указатель на функцию (тот же тип, что и у функции)
    prtnod = nod;
    int a, b;
    cout << "Введите 2 числа через пробел: " << endl;
    cin >> a >> b;
    cout << "NOD = " << prtnod(a, b) << endl;
    return 0;
}

int nod(int n1, int n2) {
    if (n2 == 0) return n1;
    return nod(n2, n1 % n2);
}