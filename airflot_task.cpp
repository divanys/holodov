//
// Created by divan on 10/4/23.
//
#include <iostream>
#include <string>
#include <cstring>

#define M 15


using namespace std;
struct Airflot {
    char where[M];
    int number;
    char type[M];
};

int main() {
    static int n = 3;
    Airflot fly[n];

    for (int i = 0; i < n; i++) {
        cout << "\nВведите номер рейса ";
        cin >> fly[i].number;
        cout << "\nВведите тип самолёта ";
        cin >> fly[i].where;
        cout << "\nВведите пункт назначения ";
        cin >> fly[i].type;
    }
    char cur[M];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(fly[i].where, fly[j].where) > 0) {
                strcpy(cur, fly[i].where);
                strcpy(fly[i].where, fly[j].where);
                strcpy(fly[j].where, cur);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fly[i].where << " " << fly[i].number << " " << fly[i].type << endl;
    }

    char temp[M];
    int count = 0;
    while (strcmp(temp, "exit")) {
        cout << "Введите желаемый тип самолёта ";
        cin >> temp;

        for (int i = 0; i < n; i++) {
            if (strcmp(fly[i].type, temp) == 0) {
                cout << endl << fly[i].where << " " << fly[i].number << endl;
                count++;
            }
        }

        if (count == 0) cout << "\nНет таких рейсов!\n";
    }
    return 0;
}

