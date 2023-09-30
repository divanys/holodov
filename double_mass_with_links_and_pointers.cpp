//
// Created by divan on 9/29/23.
//
// Объявите указатель на массив типа int и предложите пользователю
// выбрать его размер. Далее напишите четыре функции: первая должна выделить память для массива,
//        вторая – заполнить ячейки данными, третья – показать данные на
//        экран, четвертая – освободить занимаемую память. Программа
//        должна предлагать пользователю продолжать работу (создавать новые динамические массивы)
//        или выйти из программы.


#include <iostream>
#include <array>
#include <time.h>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

int *giveMemoryToArr(int *startPtr, int sizeOfArr);

void fillArr(int *ptrArr, int sizeOfArr);

void showArr(int *ptrArr, int sizeOfArr);

int *freeMemory(int *ptrArr);

double avgg(int *ptrArr, int sizeOfArr);

array<int, 2> even_and_uneven(int *ptrArr, int sizeOfArr);

int mult(int *ptrArr, int sizeOfArr);

void degree(int *ptrArr, int sizeOfArr);

map<string, int> find_min_and_max_count(int *ptrArr, int sizeOfArr);

int main() {
    int *pArrForFill = 0;
    char userAnswer = 0;
    do {
        int sizeOfArray = 0;
        cout << "Размер массива: ";
        cin >> sizeOfArray;

        pArrForFill = giveMemoryToArr(pArrForFill, sizeOfArray);
        fillArr(pArrForFill, sizeOfArray);
        cout << "Our array is" << endl;
        showArr(pArrForFill, sizeOfArray);
        cout << "\nAVG = " << avgg(pArrForFill, sizeOfArray) << endl;
        cout << "1. Количество чётных элементов = " << even_and_uneven(pArrForFill, sizeOfArray)[0]
             << "\n   Количество нечётных элементов = " << even_and_uneven(pArrForFill, sizeOfArray)[1] << endl;
        cout << "2. Произведение элементов чётных позиций = " << mult(pArrForFill, sizeOfArray) << endl;
        cout << "3. Возвели во вторую степень элементы нечётных позиций:" << endl;
        degree(pArrForFill, sizeOfArray);
        showArr(pArrForFill, sizeOfArray);
        // 4 задание у нас выявляет макс и мин среди уже возведённых во 2 степень элементов
        map<string, int> result = find_min_and_max_count(pArrForFill, sizeOfArray);
        cout << "4. Выявили максимальные и минимальные элементы и посчитали их количество" << endl;
        cout << "Min: " << result["min"] << ", Count: " << result["minCount"] << endl;
        cout << "Max: " << result["max"] << ", Count: " << result["maxCount"] << endl;


        pArrForFill = freeMemory(pArrForFill);

        cout << "\nПродолжить (1). Выйти (0): ";
        cin >> userAnswer;

    } while (userAnswer != '0');
    return 0;
}

int *giveMemoryToArr(int *ptrArr, int sizeOfArr) {
    ptrArr = new int[sizeOfArr];
    return ptrArr;
}

void fillArr(int *ptrArr, int sizeOfArr) {
    srand(time(NULL));
    for (int i = 0; i < sizeOfArr; i++) {
        ptrArr[i] = 1 + rand() % 10;
    }
}

void showArr(int *ptrArr, int sizeOfArr) {
    for (int i = 0; i < sizeOfArr; i++) {
        cout << ptrArr[i] << " ";
    }
    cout << endl;
}

int *freeMemory(int *ptrArr) {
    delete[] ptrArr;
    ptrArr = 0;
    return ptrArr;
}

// среднееарифм значение всего массива
double avgg(int *ptrArr, int sizeOfArr) {
    double sum = 0;
    for (int i = 0; i < sizeOfArr; i++) {
        sum += ptrArr[i];
    }
    return (sum / sizeOfArr);
}


// homework

// дописать функции:
// 1. посчитать количество чётных и нечётных элементов
array<int, 2> even_and_uneven(int *ptrArr, int sizeOfArr) {
    int even = 0, uneven = 0;

    for (int i = 0; i < sizeOfArr; i++) {
        if (ptrArr[i] % 2 == 0) {
            even++;
        } else if (ptrArr[i] % 2 == 1) {
            uneven++;
        }
    }

    array<int, 2> lst_even_and_uneven = {even, uneven};
    return lst_even_and_uneven;
}

// 2. посчитать произведение элементов на чётных позициях
int mult(int *ptrArr, int sizeOfArr) {
    double mult = 1;
    for (int i = 0; i < sizeOfArr; i++) {
        if (i % 2 == 0) {
            mult *= ptrArr[i];
        }
    }
    return mult;
}

// 3. возвести в ^2 элементы нечётных позиций
void degree(int *ptrArr, int sizeOfArr) {
    for (int i = 0; i < sizeOfArr; i++) {
        if (i % 2 == 1) {
            ptrArr[i] = pow(ptrArr[i], 2);
        }
    }
}

// 4. выявить макс и мин элементы и посчитать их количество
map<string, int> find_min_and_max_count(int *ptrArr, int sizeOfArr) {
    map<string, int> result;

    int min = ptrArr[0];
    int max = ptrArr[0];

    for (int i = 0; i < sizeOfArr; i++) {
        int num = ptrArr[i];
        if (num < min) {
            min = num;
        }
        if (num > max) {
            max = num;
        }
    }

    result["min"] = min;
    result["max"] = max;

    int minCount = 0;
    int maxCount = 0;

    for (int i = 0; i < sizeOfArr; i++) {
        int num = ptrArr[i];
        if (num == min) {
            minCount++;
        }
        if (num == max) {
            maxCount++;
        }
    }

    result["minCount"] = minCount;
    result["maxCount"] = maxCount;

    return result;
}

// 5. переделать под 2-мерный массив всю эту конструкцию (в отдельном файле)