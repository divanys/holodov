//
// Created by divan on 10/8/23.
//

//      под звёздочкой:
//              Программа такая же про модели

#include <iostream>

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

void showDataAVG80(const WondWom *Obj, const int amount);

double avg(const WondWom *Obj, const int amount);

void swapStudents(WondWom &a, WondWom &b);

void sortByAge(WondWom *Obj, const int amount);

int main() {
    WondWom *OurWondWom = 0;
    int wondWomAmount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных

    do {
        OurWondWom = AddStruct(OurWondWom, wondWomAmount);
        setData(OurWondWom, wondWomAmount);
        wondWomAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();  // очищение оператора cin
    } while (YesOrNot != 0);

    cout << "\nЗадание 2.\nВывести в табличной форме данный массив." << endl;
    showData(OurWondWom, wondWomAmount);

    cout << "\nЗадание 3.\nВывести на экран список моделей со ср размером больше 80." << endl;
    showDataAVG80(OurWondWom, wondWomAmount);

    cout << "\nЗадание 4.\nУпорядочить массив по возрасту." << endl;
    sortByAge(OurWondWom, wondWomAmount); // Упорядочиваем по возрасту
    showData(OurWondWom, wondWomAmount);

    delete[] OurWondWom;
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
    cout << "Имя ";
    cin.getline(Obj[amount].name, 32);
    cout << "Возраст ";
    cin >> Obj[amount].age;
    cout << "Рост ";
    cin >> Obj[amount].height;
    cout << "Вес ";
    cin >> Obj[amount].weight;
    cout << "Английский ";
    cin >> Obj[amount].engKnow;
    cout << "Объёмы: ";
    cin >> Obj[amount].volume.breast >> Obj[amount].volume.waist >> Obj[amount].volume.hips;
    cin.get();
    cout << endl;
}

void showData(const WondWom obj[], int amount) {
    cout << "№\t" << "Имя\t\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский\t" << endl;
    cout << "=====================================================================================\n";

    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "\t" << obj[i].name << "\t" << obj[i].age << "\t" << obj[i].height << "\t" << obj[i].weight
             << "\t" << obj[i].volume.breast << "/" << obj[i].volume.waist << "/" << obj[i].volume.hips << "\t"
             << obj[i].engKnow << endl;
    }
}

// Вывести на экран список моделей со ср размерами больше 80
double avg(const Size &size) {
    double sum = size.hips + size.waist + size.breast;

    return sum / 3;
}

void showDataAVG80(const WondWom *Obj, const int amount) {
    int YorN = 0;

    cout << "№\t" << "Имя\t\t" << "Возраст\t" << "Рост\t" << "Вес\t" << "Объёмы\t\t" << "Английский\t" << endl;
    cout << "=====================================================================================\n";

    for (int i = 0; i < amount; i++) {
        if (avg(Obj[i].volume) >= 80.0) {
            cout << i + 1 << "\t" << Obj[i].name << "\t" << Obj[i].age << "\t" << Obj[i].height << "\t" << Obj[i].weight
                 << "\t" << Obj[i].volume.breast << "/" << Obj[i].volume.waist << "/" << Obj[i].volume.hips << "\t"
                 << Obj[i].engKnow << endl;
            YorN++;
        }
    }

    if (YorN == 0) {
        cout << "Таких моделей не найдено!" << endl;
    }
}

// Упорядочить массив по возрасту
void swapStudents(WondWom &a, WondWom &b) {  // просто обмен данными
    WondWom temp = a;
    a = b;
    b = temp;
}

void sortByAge(WondWom *Obj, const int amount) {  // сортировка пузырьком помогает)
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (Obj[j].age > Obj[j + 1].age) {
                swapStudents(Obj[j], Obj[j + 1]);
            }
        }
    }
}

