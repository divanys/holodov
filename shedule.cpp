//
// Created by divan on 9/9/23.
//
#include <iostream>
using namespace std;

int main() {
   int day;
   cout << "Введите номер дня недели";
   cin >> day;
    switch (day) {
        case 1: cout << "Понедельник \n 8:00 Работа \n 19:00 Тренировка \n ";
            break;
        case 2: cout << "Вторник \n 8:00 Работа \n ";
            break;
        case 3: cout << "Среда \n 8:00 Работа \n 19:00 Бассейн \n ";
            break;
        case 4: cout << "Четверг \n 8:00 Работа \n20:00 ДР Бабушки\n ";
            break;
        case 5: cout << "Пятница \n 8:00 Работа \n17:00 Тренировка\n ";
            break;
        case 6: cout << "Суббота \n Пикник\n ";
            break;
        case 7: cout << "Воскресенье \nЧто угодно\n ";
            break;
        default: cout << "Нет такого дня))" << endl;
    }

    return 0;
}
