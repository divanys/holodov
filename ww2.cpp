//
// Created by divan on 10/4/23.
//
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
struct Size {
    int breast, waist, hips;
};
struct WondWom {
    char name[32];
    int age, height, weight;
    Size volume;
    bool engKnow;
};

void showData(const WondWom obj[], int amount) {
    cout << "№\t" << "Имя\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский\t" << endl;
    cout << "=====================================================================================\n";

    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "\t" << obj[i].name << "\t" << obj[i].age << "\t" << obj[i].height << "\t" << obj[i].weight
             << "\t" << obj[i].volume.breast << "/" << obj[i].volume.waist << "/" << obj[i].volume.hips << "\t"
             << obj[i].engKnow << endl;
    }
}

int main() {
    const int amount = 3;
    WondWom Woman[amount] = {};

    for (int i = 0; i < amount; i++) {
        cout << "Имя ";
        cin.getline(Woman[i].name, 32);
        cout << "Возраст ";
        cin >> Woman[i].age;
        cout << "Рост ";
        cin >> Woman[i].height;
        cout << "Вес ";
        cin >> Woman[i].weight;
        cout << "Английский ";
        cin >> Woman[i].engKnow;
        cout << "Объёмы ";
        cin >> Woman[i].volume.breast >> Woman[i].volume.waist >> Woman[i].volume.hips;
        cin.get();
        cout << endl;
    }

    showData(Woman, amount);
    return 0;
}

// массивы структур файл досмотреть изучить разобрать
