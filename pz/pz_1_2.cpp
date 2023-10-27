//
// Created by divan on 10/27/23.
//
// не использовать find, erase, substr
// Даны 3 слова — ваши Имя, Отчество, Фамилия в 3-х разных переменных.
// Образовать новую символьную переменную, хранящую полностью «имя отчество фамилия».
// (использовать склейку+).


#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstName, lastName, middleName;

    cout << "Введите ваше имя: ";
    getline(cin, firstName);

    cout << "Введите вашу фамилию: ";
    getline(cin, lastName);

    cout << "Введите ваше отчество: ";
    getline(cin, middleName);

    string FML = firstName + ' ' + middleName + ' ' + lastName;

    cout << "Ваше полное ИОФ: " << FML << endl;
}