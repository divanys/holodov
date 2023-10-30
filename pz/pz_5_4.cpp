//
// Created by divan on 10/27/23.
//
// Определить структурный тип, описывающий музыкальные CD-диски (название альбома, исполнитель, стиль, год выпуска, длительность, стоимость).
// Заполнить структурный массив 10-ю записями. Переписать из исходного массива в другой массив, информацию только о тех CD-дисках,
// название альбома которых начинается на сочетание букв (3—4) введенных пользователем.
// Затем новый массив отсортировать по стилю алфавита.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct CD {
    string albumName;
    string artist;
    string style;
    int releaseYear;
    double duration;
    double cost;
};

bool compareByStyle(const CD &cd1, const CD &cd2) {
    return cd1.style < cd2.style;
}

int main() {
    const int numCDs = 10;
    CD cds[numCDs];

    for (int i = 0; i < numCDs; i++) {
        cout << "Введите название альбома для диска " << i + 1 << ": ";
        cin >> cds[i].albumName;

        cout << "Введите имя исполнителя для диска " << i + 1 << ": ";
        cin >> cds[i].artist;

        cout << "Введите стиль для диска " << i + 1 << ": ";
        cin >> cds[i].style;

        cout << "Введите год выпуска для диска " << i + 1 << ": ";
        cin >> cds[i].releaseYear;

        cout << "Введите длительность (в минутах) для диска " << i + 1 << ": ";
        cin >> cds[i].duration;

        cout << "Введите стоимость для диска " << i + 1 << ": ";
        cin >> cds[i].cost;
    }

    string targetPrefix;
    cout << "Введите первые 3-4 буквы для фильтрации по названию альбома: ";
    cin >> targetPrefix;

    CD filteredCDs[numCDs];
    int filteredCount = 0;

    for (int i = 0; i < numCDs; i++) {
        if (cds[i].albumName.find(targetPrefix) == 0) {
            filteredCDs[filteredCount] = cds[i];
            filteredCount++;
        }
    }

    sort(filteredCDs, filteredCDs + filteredCount, compareByStyle);

    cout << "Информация о CD-дисках с названием альбома, начинающимся с '" << targetPrefix << "':" << endl;
    for (int i = 0; i < filteredCount; i++) {
        cout << "Название альбома: " << filteredCDs[i].albumName << endl;
        cout << "Исполнитель: " << filteredCDs[i].artist << endl;
        cout << "Стиль: " << filteredCDs[i].style << endl;
        cout << "Год выпуска: " << filteredCDs[i].releaseYear << endl;
        cout << "Длительность: " << filteredCDs[i].duration << " мин" << endl;
        cout << "Стоимость: $" << filteredCDs[i].cost << endl;
        cout << "---------------------" << endl;
    }

    return 0;
}
