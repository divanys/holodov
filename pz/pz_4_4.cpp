//
// Created by divan on 10/27/23.
//
// Создать динамические массивы, используя указатели. Дан массив b(n). Переписать в массив c(n) отрицательные элементы массива b(n),
// умноженные на 44 (со сжатием, без пустых элементов внутри).
// Затем упорядочить методом «выбора и перестановки» по возрастанию новый массив.

#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Введите размер массива: ";
    cin >> n;

    int *b = new int[n];
    int *c = new int[n];

    cout << "Введите элементы массива b: ";

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (b[i] < 0) {
            c[count] = b[i] * 44;
            count++;
        }
    }

    for (int i = 0; i < count - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < count; j++) {
            if (c[j] < c[min_index]) {
                min_index = j;
            }
        }
        // Обмен элементов
        int temp = c[i];
        c[i] = c[min_index];
        c[min_index] = temp;
    }

    cout << "Упорядоченный массив c: ";
    for (int i = 0; i < count; i++) {
        cout << c[i] << " ";
    }
    cout << endl;

    delete[] b;
    delete[] c;

    return 0;
}
