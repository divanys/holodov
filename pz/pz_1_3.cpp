//
// Created by divan on 10/27/23.
//
// При обработке строк использовать склейку +
// В программах не использовать find, erase, substr
// Образовать последовательность символов, включив в нее символы данной последовательности,
// расположенные на четных позициях (не использовать if).

#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstString, secondString = "";

    cout << "Введите строку для работы: ";
    getline(cin, firstString);

    for (int i = 0; i < firstString.size(); i += 2) {
        secondString += firstString[i];
    }

    cout << "Новая строка из элементов чётной позиции: " << secondString << endl;
}