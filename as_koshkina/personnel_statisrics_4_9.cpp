//
// Created by divan on 9/25/23.
//
// Вводится число n. Затем 2*n строк. Каждая пара строк - имя человека и его профессия. Определите, сотрудников какой
// профессии больше всего. Выведите на экран это количество, профессию и их имена на экран в том же порядке,
// в котором они вводились. Гарантируется, что будет введено не более 100 сотрудников.


#include <iostream>
#include <map>

using namespace std;

int main() {
    cout << "Введите количество ваших сотрудников" << endl;
    int n;
    cin >> n;

    map<string, string> employees;
    map<string, int> professionCount;

    cout << "Введите данные ваших сотрудников, а именно в виде: Имя<Enter>Профессия: " << endl;

    for (int i = 0; i < 2 * n; i += 2) {
        string name, profession;
        cin >> name >> profession;
        employees[name] = profession;
        professionCount[profession]++;
    }

    int maxCount = 0;
    string maxProfession;

    for (const auto &pair: professionCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxProfession = pair.first;
        }
    }

    cout << "Самая популярная профессия среди введённых это "  << maxProfession
    << "\nЕё имеют " << maxCount << " сотрудников, а именно: "<< endl;

    for (const auto &pair: employees) {
        if (pair.second == maxProfession) {
            cout << pair.first << ", ";
        }
    }

    return 0;
}


// Ввод:
// 7
// Иван
// Токарь
// Семён
// Программист
// Анатолий
// Кузнец
// Вася
// Финансист
// Кирилл
// Программист
// Оля
// Программист
// Валера
// Токарь
//