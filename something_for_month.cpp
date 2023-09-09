//
// Created by divan on 9/9/23.
//
// программа, для вывода количества дней в месяцы: месяц и год на ввод
#include <iostream>
using namespace std;

int main() {
    int month, year;
    cout << "Введите месяц и год: ";
    cin >> month >> year;
    switch (month) {

        case 1: cout << "Январь \n 31 день\n ";
            break;
        case 2: {
            if ((year % 400 == 0 || year % 100 != 0) && year % 4 == 0) {
                cout << "Февраль \n 29 дней\n ";
            } else {
                cout << "Февраль \n 28 дней\n ";
            }
        }
            break;
        case 3: cout << "Март\n 31 день \n ";
            break;
        case 4: cout << "Апрель \n 30 дней\n ";
            break;
        case 5: cout << "Май \n 31 день\n ";
            break;
        case 6: cout << "Июнь \n 30 дней\n ";
            break;
        case 7: cout << "Июль \n31 день\n ";
            break;
        case 8: cout << "Август \n31 день\n ";
            break;
        case 9: cout << "Сентябрь \n30 дней\n ";
            break;
        case 10: cout << "Октябрь \n31 день\n ";
            break;
        case 11: cout << "Ноябрь \n30 дней\n ";
            break;
        case 12: cout << "Декабрь \n31 день\n ";
            break;

        default: cout << "Нет такого дня))" << endl;
    }

    return 0;
}
