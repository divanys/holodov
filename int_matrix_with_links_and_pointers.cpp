//
// Created by divan on 9/30/23.
//

// 5. переделать под 2-мерный массив всю эту конструкцию
#include <iostream>
#include <array>
#include <ctime>
#include <cmath>
#include <map>

using namespace std;

int **giveMemoryToArr(int numRows, int numCols);

void fillArr(int **ptrArr, int numRows, int numCols);

void showArr(int **ptrArr, int numRows, int numCols);

void freeMemory(int **ptrArr, int numRows);

double avgg(int **ptrArr, int numRows, int numCols);

array<int, 2> even_and_uneven(int **ptrArr, int numRows, int numCols);

int mult(int **ptrArr, int numRows, int numCols);

void degree(int **ptrArr, int numRows, int numCols);

map<string, int> find_min_and_max_count(int **ptrArr, int numRows, int numCols);

int main() {
    int **pArrForFill;
    char userAnswer = 0;

    do {
        int numRows = 0, numCols = 0;

        cout << "Количество строк: ";
        cin >> numRows;

        cout << "Количество столбцов: ";
        cin >> numCols;

        pArrForFill = giveMemoryToArr(numRows, numCols);

        fillArr(pArrForFill, numRows, numCols);

        cout << "Наш массив:" << endl;
        showArr(pArrForFill, numRows, numCols);

        cout << "\nAVG = " << avgg(pArrForFill, numRows, numCols) << endl;

        array<int, 2> evenUneven = even_and_uneven(pArrForFill, numRows, numCols);
        cout << "1. Количество чётных элементов = " << evenUneven[0]
             << "\n   Количество нечётных элементов = " << evenUneven[1] << endl;

        cout << "2. Произведение элементов чётных позиций = " << mult(pArrForFill, numRows, numCols) << endl;

        cout << "3. Возвели во вторую степень элементы нечётных позиций:" << endl;
        degree(pArrForFill, numRows, numCols);
        showArr(pArrForFill, numRows, numCols);

        map<string, int> result = find_min_and_max_count(pArrForFill, numRows, numCols);
        cout << "4. Выявили максимальные и минимальные элементы и посчитали их количество" << endl;
        cout << "Min: " << result["min"] << ", Count: " << result["minCount"] << endl;
        cout << "Max: " << result["max"] << ", Count: " << result["maxCount"] << endl;

        freeMemory(pArrForFill, numRows);

        cout << "\nПродолжить (1). Выйти (0): ";
        cin >> userAnswer;

    } while (userAnswer != '0');

    return 0;
}

int **giveMemoryToArr(int numRows, int numCols) {
    int **ptrArr = new int *[numRows];
    for (int i = 0; i < numRows; ++i) {
        ptrArr[i] = new int[numCols];
    }
    return ptrArr;
}

void fillArr(int **ptrArr, int numRows, int numCols) {
    srand(time(NULL));
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            ptrArr[i][j] = 1 + rand() % 10;
        }
    }
}

void showArr(int **ptrArr, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << ptrArr[i][j] << " ";
        }
        cout << endl;
    }
}

void freeMemory(int **ptrArr, int numRows) {
    for (int i = 0; i < numRows; ++i) {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;
}

double avgg(int **ptrArr, int numRows, int numCols) {
    double sum = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            sum += ptrArr[i][j];
        }
    }
    return (sum / (numRows * numCols));
}

array<int, 2> even_and_uneven(int **ptrArr, int numRows, int numCols) {
    int even = 0, uneven = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (ptrArr[i][j] % 2 == 0) {
                even++;
            } else if (ptrArr[i][j] % 2 == 1) {
                uneven++;
            }
        }
    }
    array<int, 2> lst_even_and_uneven = {even, uneven};
    return lst_even_and_uneven;
}

int mult(int **ptrArr, int numRows, int numCols) {
    int mult = 1;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((i * numCols + j) % 2 == 0) {
                mult *= ptrArr[i][j];
            }
        }
    }
    return mult;
}

void degree(int **ptrArr, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if ((i * numCols + j) % 2 == 1) {
                ptrArr[i][j] = pow(ptrArr[i][j], 2);
            }
        }
    }
}

map<string, int> find_min_and_max_count(int **ptrArr, int numRows, int numCols) {
    map<string, int> result;
    int min = ptrArr[0][0];
    int max = ptrArr[0][0];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int num = ptrArr[i][j];
            if (num < min) {
                min = num;
            }
            if (num > max) {
                max = num;
            }
        }
    }

    result["min"] = min;
    result["max"] = max;

    int minCount = 0;
    int maxCount = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            int num = ptrArr[i][j];
            if (num == min) {
                minCount++;
            }
            if (num == max) {
                maxCount++;
            }
        }
    }

    result["minCount"] = minCount;
    result["maxCount"] = maxCount;

    return result;
}
