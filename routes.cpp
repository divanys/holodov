//
// Created by divan on 10/15/23.
//
//Создать структуру маршрут с полями: пункт отправления, время отправления, вид транспорта, пункт прибытия,
// время прибытия, цена поездки.
//
//1. Пользователь вручную вводит информацию о маршрутах, заранее не знаю, сколько маршрутов он введет.
//
//2. Вывести всю введенную информацию в табличном виде на экран.
//
//3. После вывода информации предложить пользователю ввести тип транспорта. После чего выдать информацию о маршрутах,
// по которым ездит данный тип транспорта.

#include <iostream>
#include <cstring>

using namespace std;

struct Route {
    char departurePoint[64]; // Пункт отправления
    char departureTime[16];  // Время отправления
    char transportType[32];  // Вид транспорта
    char arrivalPoint[64];   // Пункт прибытия
    char arrivalTime[16];    // Время прибытия
    float price;             // Цена поездки
};

Route *AddRoute(Route *Obj, const int amount);
void setData(Route *Obj, const int amount);
void showRoutes(const Route *Obj, const int amount);
void showRoutesByTransport(const Route *Obj, const int amount, const char* transport);

int main() {
    Route *Routes = nullptr;
    int routeCount = 0;
    int continueInput = 0;

    do {
        Routes = AddRoute(Routes, routeCount);
        setData(Routes, routeCount);
        routeCount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> continueInput;
        cin.get();  // очищение оператора cin
    } while (continueInput != 0);

    cout << "\nЗадание 2.\nВывести в табличной форме данные о маршрутах." << endl;
    showRoutes(Routes, routeCount);

    cout << "\nЗадание 3.\nВведите тип транспорта: ";
    char transport[32];
    cin.getline(transport, 32);
    showRoutesByTransport(Routes, routeCount, transport);

    delete[] Routes;
    return 0;
}

Route *AddRoute(Route *Obj, const int amount) {
    if (amount == 0) {
        Obj = new Route[amount + 1]; // выделение памяти для первой структуры
    } else {
        Route *tempObj = new Route[amount + 1];

        for (int i = 0; i < amount; i++) {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;
        Obj = tempObj;
    }

    return Obj;
}

void setData(Route *Obj, const int amount) {
    cout << "Пункт отправления: ";
    cin.getline(Obj[amount].departurePoint, 64);
    cout << "Время отправления: ";
    cin.getline(Obj[amount].departureTime, 16);
    cout << "Вид транспорта: ";
    cin.getline(Obj[amount].transportType, 32);
    cout << "Пункт прибытия: ";
    cin.getline(Obj[amount].arrivalPoint, 64);
    cout << "Время прибытия: ";
    cin.getline(Obj[amount].arrivalTime, 16);
    cout << "Цена поездки: ";
    cin >> Obj[amount].price;
    cin.get(); // очищение оператора cin
    cout << endl;
}

void showRoutes(const Route *obj, int amount) {
    cout << "№\t" << "Отправление\t" << "Время\t" << "Тип транспорта\t" << "Прибытие\t" << "Время\t" << "Цена\t" << endl;
    cout << "===========================================================================\n";

    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "\t" << obj[i].departurePoint << "\t" << obj[i].departureTime << "\t"
             << obj[i].transportType << "\t" << obj[i].arrivalPoint << "\t" << obj[i].arrivalTime
             << "\t" << obj[i].price << endl;
    }
}

void showRoutesByTransport(const Route *obj, const int amount, const char* transport) {
    int YorN = 0;

    cout << "№\t" << "Отправление\t" << "Время\t" << "Тип транспорта\t" << "Прибытие\t" << "Время\t" << "Цена\t" << endl;
    cout << "===========================================================================\n";

    for (int i = 0; i < amount; i++) {
        if (strcmp(obj[i].transportType, transport) == 0) {
            cout << i + 1 << "\t" << obj[i].departurePoint << "\t" << obj[i].departureTime << "\t"
                 << obj[i].transportType << "\t" << obj[i].arrivalPoint << "\t" << obj[i].arrivalTime
                 << "\t" << obj[i].price << endl;
            YorN++;
        }
    }

    if (YorN == 0) {
        cout << "Маршруты с таким типом транспорта не найдены!" << endl;
    }
}
