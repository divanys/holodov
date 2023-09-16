//
// Created by divan on 9/16/23.
//
#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;


void Menu() {
    cout << "1. Ввод массива.\n";
    cout << "2. Вывод массива.\n";
    cout << "3. Максимальный элемент.\n";
    cout << "4. Минимальный элемент.\n";
    cout << "5. Индекс максимального элемента.\n";
    cout << "6. Индекс минимального элемента.\n";
    cout << "7. Колличество четных элементов.\n";
    cout << "8. Колличество нечетных элементов.\n";
    cout << "9. Сумма положительных элементов стоящих на нечетных позициях.\n";
    cout << "10. Произведение отрицательных элементов стоящих на четных позициях.\n";
    cout << "11. Среднее арифметическое значение массива.\n";
    cout << "12. Перезаписать массив и все нечетный элементы возвести в квадрат, а все четные в куб.\n";
    cout << "13. Выйти.\n";

}

int max(int *n, int t) {
    int max = n[0];
    for (int i = 0; i < t; i++) {
        if (n[i] > max) {
            max = n[i];
        }
    }
    return max;
}

int min(int *n, int t) {
    int min = n[0];
    for (int i = 0; i < t; i++) {
        if (n[i] < min) {
            min = n[i];
        }
    }
    return min;
}

int main() {
    const int n = 5;
    int mas[n];
    for (int i = 0; i < n; i++) {
        mas[i] == 0;
    }
    int menu;
    setlocale(0, "");

    m1:
    Menu();
    cin >> menu;

    switch (menu) {
        case 1: {
            int dopmenu;

            m2:
            cout << "\nВведите подменю\n";
            cout << "1 - Вручную\n";
            cout << "2 - Рандом\n";
            cin >> dopmenu;

            if (dopmenu == 1) {
                for (int i = 0; i < n; i++) {
                    cout << "Введите " << i + 1 << " элемент: ";
                    cin >> mas[i];
                }
            } else if (dopmenu == 2) {
                srand(time(NULL));
                for (int i = 0; i < n; i++) {
                    mas[i] = -4 + rand() % 11;
                }
            } else {
                cout << "EERRRROORR of input\n";
                goto m2;
            }
            break;
        }

        case 2: {
            for (int i = 0; i < n; i++) {
                cout << mas[i] << " ";
            }
            break;
        }

        case 3: {
            cout << "Максимальный элемент: " << max(mas, n) << endl;
            break;
        }

        case 4: {
            cout << "Минимальный элемент: " << min(mas, n) << endl;
            break;
        }

        case 5: {
            cout << "Индексы максимальных элементов: ";
            for (int i = 0; i < n; i++) {
                if (mas[i] == max(mas, n)) {
                    cout << i << " ";
                }
            }
            cout << endl;
            break;
        }

        case 6: {
            cout << "Индексы минимальных элементов: ";
            for (int i = 0; i < n; i++) {
                if (mas[i] == min(mas, n)) {
                    cout << i << " ";
                }
            }
            cout << endl;
            break;
        }

        case 7: {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (mas[i] % 2 == 0) {
                    count++;
                }
                cout << "Количество чётных элементов: " << count << endl;
            }
            break;
        }

        case 8: {
            for (int i = 0; i < n; i++) {
                cout << mas[i] << " ";
            }
            break;
        }

        // Сумма положительных элементов стоящих на нечетных позициях.
        case 9: {
            int sumsum = 0;
            for (int i = 0; i < n; i++) {
                if (mas[i] > 0 && i % 2 == 1) {
                    sumsum += mas[i];
                }
            }
            cout << "Сумма равна " << sumsum << endl;
            break;
        }

        // Произведение отрицательных элементов стоящих на четных позициях
        case 10: {
            int mulmul = 1;
            for (int i = 0; i < n; i++) {
                if (mas[i] < 0 && i % 2 == 0) {
                    mulmul *= mas[i];
                }
            }
            cout << "Произведение равно " << mulmul << endl;
            break;
        }

        // Среднее арифметическое значение массива
        case 11: {
            double sumsum = 0;
            for (int i = 0; i < n; i++) {
                    sumsum += mas[i];
            }
            cout << "Среднеарифметическое значение массива равно  " << sumsum / n << endl;
            break;
        }

        // Перезаписать массив и все нечетные элементы возвести в квадрат, а все четные в куб.
        case 12: {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1) {
                    mas[i] = pow(mas[i], 2);
                }
                if (i % 2 == 0) {
                    mas[i] = pow(mas[i], 3);
                }
            }
            break;
        }

        case 13: {
            exit(0);
        }

        default: {
            cout << "EERRRROORR of input\n";
        }
    }
    goto m1;

    return 0;

}