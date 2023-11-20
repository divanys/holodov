//
// Created by divan on 11/20/23.
//
#include <iostream>
#include "array.h"

using namespace std;

int main() {
    Array myArray1;  // 10-тый элементный объект класса Array, по умолчанию
    Array myArray2(15);  // 15-тый элементный объект класса

    cout << "Размер массива myArray1: " << myArray1.getSize() << endl;
    cout << "Элементы массива myArray1, после ero создания:\n";

    myArray1.getArray();  // вывод элементов массива с помощью метода класса Array

    cout << "Размер массива myArray2: " << myArray2.getSize() << endl;
    cout << "Элементы массива myArray2, после его создания:\\n";
    cout << myArray2;  // вывод элементов массива с помощью перегруженного оператора вывода
    cout << "Введите 10 чисел: ";

    myArray1.setArray();  // заполнение массива с помощью метода класса Array

    cout << "Введенный массив: " << myArray1;
    cout << "Введите 15 чисел: ";

    cin >> myArray2;  // заполнение массива с помощью перегруженного оператора ввода

    cout << "Введенный массив: " << myArray2;  // введенный массив

    Array myArray3(myArray1);  // создаём объект класса Array, используя конструктор копирования

    cout << "Размер массива myArray3: " << myArray1.getSize() << endl;
    cout << myArray3;  // вывод элементов массива

    myArray3 = myArray2;  // присваиваем массиву myArray3 массив myArray2
    cout << myArray3;  // вывод элементов массива myArray3

    if (myArray1 == myArray2) {
        cout << "Массивы myArray1 и myArray2 равны!\n";
    } else {
        cout << "Массивы myArray1 и myArray2 не равны!\n";
    }

    // вывод элемента массива, используя перегруженную операцию взятия индекса
    cout << "Элемента массива myArray1: " << myArray1[myArray1.getSize() - 1] << endl;

    Array myArray4 = myArray2 + myArray3;  // перегруженная операция сложения

    cout << "Массив myArray4:\n " << myArray4;

    myArray4 += 111;  // добавление элемента 111 в конец массива
    cout << "Массив myArray + 8: \n" << ((myArray4 += 112) += 113);

    // удаляем элементы массива myArray4: 111 112 113 посредством перегруженной операции минус
    cout << (myArray4 - 111 - 112 - 113);

    int pos;

    if ((pos = myArray4.search(30)) != -1) {
        cout << "Позиция искомого элемента: " << pos << endl;
    } else {
        cout << "Искомый элемент не найден!\n";
    }

    myArray4.choicesSort();  // сортировка по возрастанию
    cout << myArray4;

    return 0;

}
