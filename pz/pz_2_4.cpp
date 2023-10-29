//
// Created by divan on 10/27/23.
//
// Дан список фамилий сотрудников. Переписать в другой список только те фамилии, в которых есть вторая буква <l>.
// Затем упорядочить по алфавиту второй список методом «пузырька»
#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cout << "Введите количество фамилий: ";
    cin >> n;

    string *surnames = new string[n];

    cout << "Введите фамилии сотрудников:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> surnames[i];
    }

    string *filteredSurnames = new string[n];
    int filteredCount = 0;

    // Фильтрация фамилий
    for (int i = 0; i < n; i++) {
        string surname = surnames[i];

        if (surname.size() >= 2) {
            int lCount = 0;

            for (char c: surname) {
                if (c == 'l' || c == 'L') {
                    lCount++;
                }
            }

            if (lCount == 2) {
                filteredSurnames[filteredCount] = surname;
                filteredCount++;
            }
        }
    }

    for (int i = 0; i < filteredCount - 1; i++) {
        for (int j = 0; j < filteredCount - i - 1; j++) {
            if (filteredSurnames[j] > filteredSurnames[j + 1]) {
                swap(filteredSurnames[j], filteredSurnames[j + 1]);
            }
        }
    }

    cout << "Отфильтрованные и отсортированные фамилии:" << endl;
    for (int i = 0; i < filteredCount; i++) {
        cout << filteredSurnames[i] << endl;
    }

    delete[] surnames;
    delete[] filteredSurnames;

    return 0;
}
