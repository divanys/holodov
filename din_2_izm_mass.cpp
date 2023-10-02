//
// Created by divan on 10/2/23.
//
//Объявить и заполнить двумерный динамический массив
//случайными числами от 10 до 50 Показать его на экран. Для
//        заполнения и показа на экран написать отдельные функции.
//(подсказка: функции должны принимать три параметра –
//указатель на динамический массив, количество строк,
//количество столбцов). Количество строк и столбцов вводит пользователь

#include <iostream>
#include <ctime>

using namespace std;

void show2Arr(int **ArrForChange, int strAmount, int colAmount);

void fill2Array(int **ArrForChange, int strAmount, int colAmount);

int main() {
    int stringAmount = 0;
    int columnAmount = 0;
    cout << "Введите размерность двумерного массива!\n";
    cout << "Строк: ";
    cin >> stringAmount;
    cout << "Столбцов: ";
    cin >> columnAmount;
    // создавая двумерный динамический массив используем указатель на указатель
    int **ArrayForChange = new int *[stringAmount];
    for (int i = 0; i < stringAmount; i++) {
        ArrayForChange[i] = new int[columnAmount];
    }
    fill2Array(ArrayForChange, stringAmount, columnAmount); // заполнение массива
    show2Arr(ArrayForChange, stringAmount, columnAmount); // показ на экран

    //Очистка памяти динамического двумерного массива
    for (int i = 0; i < stringAmount; i++) {
        delete[] ArrayForChange[i];
    }
    delete[] ArrayForChange;
    return 0;
}

void show2Arr(int **ArrForChange, int strAmount, int colAmount) {
    cout << endl << endl;
    for (int i = 0; i < strAmount; i++) {
        cout << " | ";
        for (int j = 0; j < colAmount; j++) {
            cout << ArrForChange[i][j] << " ";
        }
        cout << "|" << endl;
    }
}

//заполнение элементов двумерного массива случайными значениям
void fill2Array(int **ArrForChange, int strAmount, int colAmount) {
    srand(time(0));
    for (int i = 0; i < strAmount; i++) {
        for (int j = 0; j < colAmount; j++) {
            ArrForChange[i][j] = 10 + rand() % 41;
        }
    }
}