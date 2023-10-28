// Разработка программ на языке С++ с использованием массива строк.
//
// Created by divan on 10/27/23.
//
// Задан список из десяти городов (массив [.]string). Найти количество городов,
// название которых заканчивается сочетанием букв «град» или “grad”.
#include <iostream>
#include <string>
#include <clocale>

using namespace std;

// Функция для поиска городов, название которых заканчивается на "град"
int findCitiesWithGrad(const string cities[], int size) {
    int count = 0;
    setlocale(LC_ALL, "Rus");

    for (int i = 0; i < size; i++) {
        int pos = cities[i].find("град");
        if (pos >= 0) {
            cout << cities[i] << endl;
            count += 1;
        }
    }

    return count;
}

// Функция для поиска городов, название которых заканчивается на "grad"
int findCitiesWithGradEnglish(const string cities[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int pos = cities[i].find("grad");
        if (pos >= 0) {
            cout << cities[i] << endl;
            count += 1;
        }
    }
    return count;
}

int main() {
    string cities[] = {
            "Москва",
            "Санкт-Петербург",
            "Нью-Йорк",
            "Вашингтон",
            "Киевград",
            "Волгоград",
            "Лондонград",
            "Ростов",
            "grad",
            "Citygrad"
    };

    int size = sizeof(cities) / sizeof(cities[0]);

    int countWithGrad = findCitiesWithGrad(cities, size);
    int countWithGradEnglish = findCitiesWithGradEnglish(cities, size);

    cout << "Количество городов с окончанием 'град' или 'grad': " << countWithGrad + countWithGradEnglish << endl;

    return 0;
}