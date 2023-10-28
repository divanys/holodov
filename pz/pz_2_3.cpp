//
// Created by divan on 10/27/23.
//
// Задан список из десяти городов (массив [.]string). Найти название города с максимальным количеством букв <g>
#include <iostream>
#include <string>

using namespace std;

// Функция для поиска города с максимальным количеством букв 'g'
string findCityWithMaxG(const string cities[], int size) {
    int maxGCount = 0;
    string cityWithMaxG;

    for (int i = 0; i < size; i++) {
        int gCount = 0;
        for (char c: cities[i]) {
            if (c == 'g' || c == 'G') {
                gCount++;
            }
        }
        if (gCount > maxGCount) {
            maxGCount = gCount;
            cityWithMaxG = cities[i];
        }
    }

    return cityWithMaxG;
}

int main() {
    string cities[] = {
            "Gorodg",
            "negorodgradgta",
            "gta",
            "Вашингтон",
            "Киевград",
            "ddffjjkks",
            "Лондонград",
            "Град",
            "grad",
            "Citygrad"
    };

    int size = sizeof(cities) / sizeof(cities[0]);

    string cityWithMaxG = findCityWithMaxG(cities, size);

    if (!cityWithMaxG.empty()) {
        cout << "Город с максимальным количеством букв 'g': " << cityWithMaxG << endl;
    } else {
        cout << "Ни один из городов не содержит буквы 'g'." << endl;
    }

    return 0;
}