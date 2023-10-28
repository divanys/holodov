//
// Created by divan on 10/27/23.
//
// Задан список из десяти городов (массив [.]string). Поменять местами названия самого длинного и самого короткого слова.
#include <iostream>
#include <string>

using namespace std;

// Функция для обмена местами самого длинного и самого короткого слова
void swapLongestAndShortest(string cities[], int size) {
    int shortestIndex = 0;
    int longestIndex = 0;

    for (int i = 1; i < size; i++) {
        if (cities[i].length() < cities[shortestIndex].length()) {
            shortestIndex = i;
        }
        if (cities[i].length() > cities[longestIndex].length()) {
            longestIndex = i;
        }
    }

    swap(cities[shortestIndex], cities[longestIndex]);
}

int main() {
    string cities[] = {
            "Москва",
            "Санкт-Петербург",
            "Нью-Йорк",
            "Лондон",
            "Париж",
            "Берлин",
            "Рим",
            "Афины",
            "Токио",
            "Мадрид"
    };

    int size = sizeof(cities) / sizeof(cities[0]);

    cout << "Исходный список городов:" << endl;
    for (int i = 0; i < size; i++) {
        cout << cities[i] << endl;
    }

    swapLongestAndShortest(cities, size);

    cout << "\nСписок городов после обмена:" << endl;
    for (int i = 0; i < size; i++) {
        cout << cities[i] << endl;
    }

    return 0;
}