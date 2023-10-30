//
// Created by divan on 10/27/23.
//
// Определить комбинированный (структурный) тип для представления анкеты жителя,
// состоящей из его фамилии, названия города, где он проживает, и городского адреса.
// Адрес состоит из полей: «улица», «дом», «квартира».
// Ввести информацию по 10 жителям.
// Переписать из исходного массива в другой массив, информацию только о тех жителях, фамилия которых начинается на указанную букву
// (указанную букву вводит пользователь с клавиатуры).

#include <iostream>
#include <string>
using namespace std;

// Структура для представления адреса
struct Address {
    string street;
    int house;
    int apartment;
};

// Структура для представления анкеты жителя
struct Resident {
    string lastName;
    string city;
    Address address;
};

int main() {
    const int numResidents = 10; // Количество жителей
    Resident residents[numResidents];

    // Ввод информации о 10 жителях
    for (int i = 0; i < numResidents; i++) {
        cout << "Введите фамилию жителя " << i + 1 << ": ";
        cin >> residents[i].lastName;

        cout << "Введите название города, где живет житель " << i + 1 << ": ";
        cin >> residents[i].city;

        cout << "Введите улицу для жителя " << i + 1 << ": ";
        cin >> residents[i].address.street;

        cout << "Введите номер дома для жителя " << i + 1 << ": ";
        cin >> residents[i].address.house;

        cout << "Введите номер квартиры для жителя " << i + 1 << ": ";
        cin >> residents[i].address.apartment;
    }

    char targetLetter;
    cout << "Введите букву, на которую должна начинаться фамилия: ";
    cin >> targetLetter;

    // Создаем второй массив для хранения информации только о жителях с указанной буквой в фамилии
    Resident filteredResidents[numResidents];
    int filteredCount = 0;

    for (int i = 0; i < numResidents; i++) {
        if (residents[i].lastName[0] == targetLetter) {
            filteredResidents[filteredCount] = residents[i];
            filteredCount++;
        }
    }

    // Вывод информации о жителях с указанной буквой в фамилии
    cout << "Жители, фамилии которых начинаются с буквы '" << targetLetter << "':" << endl;
    for (int i = 0; i < filteredCount; i++) {
        cout << "Фамилия: " << filteredResidents[i].lastName << endl;
        cout << "Город: " << filteredResidents[i].city << endl;
        cout << "Адрес: " << filteredResidents[i].address.street << ", дом " << filteredResidents[i].address.house << ", квартира " << filteredResidents[i].address.apartment << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}
