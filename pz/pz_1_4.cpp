//
// Created by divan on 10/27/23.
//
// не использовать find
// Задан текст из символов латинского алфавита, содержащий букву <a>.
// Напечатать все символы, расположенные за первой буквой <a> до ее второго вхождения или до конца текста.


#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    int count = 0;

    cout << "Введите тест: ";
    getline(cin, text);

    for (int i = 0; i < text.size(); i++) {
        if (count == 0 && text[i] == 'a') {
            count++;
        } else if (count == 1 && text[i] != 'a') {
            cout << text[i];
        } else if (count == 1 && text[i] == 'a') {
            count++;
            break;
        }
    }

    cout << endl;

    if (count < 2) {
        cout << "Вторая буква 'a' не найдена в тексте." << endl;
    }
}