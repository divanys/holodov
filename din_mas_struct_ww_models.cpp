//
// Created by divan on 10/6/23.
// переделать программу с моделями (за 4 октября) под динамический массив структур

//
// Created by divan on 10/6/23.
//
#include<iostream>

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

WondWom *AddStruct(WondWom *Obj, const int amount);

void setData(WondWom *Obj, const int amount);

void showData(const WondWom *Obj, const int amount);

int main() {
    WondWom *OurWondWem = 0;
    int wemAmount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных
    do {
        OurWondWem = AddStruct(OurWondWem, wemAmount);
        setData(OurWondWem, wemAmount);
        wemAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();  // очищение оператора cin
    } while (YesOrNot != 0);
    showData(OurWondWem, wemAmount);
    delete[] OurWondWem;
    return 0;
}

WondWom *AddStruct(WondWom *Obj, const int amount) {
    if (amount == 0) {
        Obj = new WondWom[amount + 1]; // выделение памяти для первой структуры
    } else {
        WondWom *tempObj = new WondWom[amount + 1];
        for (int i = 0; i < amount; i++) {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;
        Obj = tempObj;
    }
    return Obj;
}

void setData(WondWom *Obj, const int amount) {
    cout << "Имя: ";
    cin.getline(Obj[amount].name, 32);
    cout << "Возраст: ";
    cin >> Obj[amount].age;
    cout << "Рост: ";
    cin >> Obj[amount].height;
    cout << "Вес: ";
    cin >> Obj[amount].weight;
    cout << "Размеры: \nгрудь: ";
    cin >> Obj[amount].volume.breast;
    cout << "талия: : ";
    cin >> Obj[amount].volume.waist;
    cout << "бёдра: ";
    cin >> Obj[amount].volume.hips;
    cout << "Знание английского: ";
    cin >> Obj[amount].engKnow;

    cin.get();
    cout << endl;
}

void showData(const WondWom *obj, const int amount) {
    cout << "№\t" << "Имя\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский\t" << endl;
    cout << "=====================================================================================\n";

    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "\t" << obj[i].name << "\t" << obj[i].age << "\t" << obj[i].height << "\t" << obj[i].weight
             << "\t" << obj[i].volume.breast << "/" << obj[i].volume.waist << "/" << obj[i].volume.hips << "\t"
             << obj[i].engKnow << endl;
    }
}

