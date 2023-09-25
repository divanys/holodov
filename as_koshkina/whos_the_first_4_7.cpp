//
// Created by divan on 9/25/23.
//
// 7. Кто первый?
// Дана строка, в которой через пробел перечислены цифры. На следующей строке вводится цифра.
// Определите индексы первого и последнего её вхождения.
//
// Ввод:					                    Вывод:
// 4 5 3 5 2 6 4 6 6 8 1 2 3 8 4 0 9 7		    0
// 4					                        28

#include <iostream>
#include <string>

using namespace std;

int main() {
    string data, number;
    cout << "Введите данные: ";
    getline(cin, data);  // считывает всю строку, включая пробелы, до символа новой строки
    cout << "Введите число для задания: ";
    cin >> number;  // считывает строку до первого пробела

    int firstIndex = data.find(number);
    int lastIndex = data.rfind(number);

    if (firstIndex != string::npos) {
        cout << "Цифра " << number << " имеет первое вхождение с индексом " << firstIndex
             << " и последнее с индексом " << lastIndex << endl;
    } else {
        cout << "Цифра " << number << " не найдена." << endl;
    }
    return 0;
}