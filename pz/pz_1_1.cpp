// Получить практические навыки разработки программ на языке C++ с использованием стандартного класса String.
//
// Created by divan on 10/27/23.
//
// не использовать find, erase, substr
// Вариант 4
// Дан текст. Определить, в каких позициях в нем встречается символ ;.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cout << "Введите текст: ";
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ';') {
            cout << "Символ ';' найден в позиции: " << i << endl;
        }
    }
}