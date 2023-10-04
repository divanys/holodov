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

void showData(const WondWom &obj) {
    cout << "Модель " << obj.name << endl;
    cout << "Возраст " << obj.age << endl;
    cout << "Рост " << obj.height << endl;
    cout << "Вес " << obj.weight << endl;
    cout << "Объёмы: \n1. " << obj.volume.breast << endl;
    cout << "2. " << obj.volume.waist << endl;
    cout << "3. " << obj.volume.hips << endl;
    cout << "Знание английского (да/нет) " << obj.engKnow << endl;

}

int main() {
    WondWom first = {};
    strcpy(first.name, "Оксана");
    first.age = 32;
    first.height = 172;
    first.weight = 55;
    first.engKnow = 1;
    first.volume.breast = 90;
    first.volume.waist = 60;
    first.volume.hips = 90;
    showData(first);
}

