//
// Created by divan on 10/27/23.
//
// Дан список фамилий сотрудников. Переписать в другой список только те фамилии, в которых есть вторая буква <l>.
// Затем упорядочить по алфавиту второй список методом «пузырька»
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для фильтрации фамилий и сохранения во втором списке
void filterSurnames(const vector<string>& originalList, vector<string>& filteredList) {
    for (const string& surname : originalList) {
        if (surname.length() >= 2 && surname[1] == 'l') {
            filteredList.push_back(surname);
        }
    }
}

// Функция для сортировки списка методом пузырька
void bubbleSort(vector<string>& surnames) {
    int size = surnames.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (surnames[j] > surnames[j + 1]) {
                swap(surnames[j], surnames[j + 1]);
            }
        }
    }
}

int main() {
    vector<string> originalList;
    vector<string> filteredList;

    int n;
    cout << "Введите количество фамилий: ";
    cin >> n;

    // Ввод фамилий сотрудников
    for (int i = 0; i < n; i++) {
        string surname;
        cout << "Введите фамилию " << i + 1 << ": ";
        cin >> surname;
        originalList.push_back(surname);
    }

    filterSurnames(originalList, filteredList);
    bubbleSort(filteredList);

    cout << "Фамилии, в которых вторая буква - 'l':\n";
    for (const string& surname : filteredList) {
        cout << surname << endl;
    }

    return 0;
}