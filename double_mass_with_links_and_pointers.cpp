//
// Created by divan on 9/29/23.
//
//Объявите указатель на массив типа double и предложите пользователю
//выбрать его размер. Далее напишите четыре функции: первая должна выделить память для массива,
//        вторая – заполнить ячейки данными, третья – показать данные на
//        экран, четвертая – освободить занимаемую память. Программа
//        должна предлагать пользователю продолжать работу (создавать новые динамические массивы ) или выйти из программы.


#include <iostream>

using namespace std;

double *giveMemoryToArr(double *startPtr, int sizeOfArr);

void fillArr(double *ptrArr, int sizeOfArr);

void showArr(double *ptrArr, int sizeOfArr);

double *freeMemory(double *ptrArr);

int main() {
    setlocale(LC_ALL, "rus");
    double *pArrForFill = 0;
    char userAnswer = 0;
    do {
        int sizeOfArray = 0;
        cout << "Размер массива: ";
        cin >> sizeOfArray;
        pArrForFill = giveMemoryToArr(pArrForFill, sizeOfArray);
        fillArr(pArrForFill, sizeOfArray);
        showArr(pArrForFill, sizeOfArray);
        pArrForFill = freeMemory(pArrForFill);
        cout << "\nПродолжить (1). Выйти (0): ";
        cin >> userAnswer;
    } while (userAnswer != '0');
    return 0;
}

double *giveMemoryToArr(double *ptrArr, int sizeOfArr) {
    ptrArr = new double[sizeOfArr];
    return ptrArr;
}

void fillArr(double *ptrArr, int sizeOfArr) {
    for (int i = 0; i < sizeOfArr; i++) {
        ptrArr[i] = (i + 1) * 0.2;
    }
}

void showArr(double *ptrArr, int sizeOfArr) {
    for (int i = 0; i < sizeOfArr; i++) {
        cout << ptrArr[i] << " ";
    }
    cout << endl;
}

double *freeMemory(double *ptrArr) {
    delete[] ptrArr;
    ptrArr = 0;
    return ptrArr;
}