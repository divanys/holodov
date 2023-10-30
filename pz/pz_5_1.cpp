// Разработка программ на языке С++ с использованием структур.
//
// Created by divan on 10/27/23.
//
// Составить программу, выводящую на экран ведомость начисленной заработной платы (Ф.И.О., должность, года и дата рождения, заработная плата).
// Вывести фамилию сотрудника с самой маленькой зарплатой.

#include <iostream>
#include <string>

using namespace std;

struct Employee {
    string fullName;
    string position;
    int birthYear;
    string birthDate;
    double salary;
};

int main() {
    const int numEmployees = 3;
    Employee employees[numEmployees];

    for (auto & employee : employees) {
        cout << "Введите Ф.И.О. сотрудника: ";
        getline(cin, employee.fullName);

        cout << "Введите должность сотрудника: ";
        getline(cin, employee.position);

        cout << "Введите год рождения сотрудника: ";
        cin >> employee.birthYear;
        cin.ignore();

        cout << "Введите дату рождения сотрудника: ";
        getline(cin, employee.birthDate);

        cout << "Введите заработную плату сотрудника: ";
        cin >> employee.salary;
        cin.ignore();
    }

    string minSalaryName = employees[0].fullName;
    double minSalary = employees[0].salary;

    for (int i = 1; i < numEmployees; i++) {
        if (employees[i].salary < minSalary) {
            minSalary = employees[i].salary;
            minSalaryName = employees[i].fullName;
        }
    }

    cout << "Ведомость начисленной заработной платы:" << endl;

    for (auto & employee : employees) {
        cout << "Ф.И.О.: " << employee.fullName << endl;
        cout << "Должность: " << employee.position << endl;
        cout << "Год рождения: " << employee.birthYear << endl;
        cout << "Дата рождения: " << employee.birthDate << endl;
        cout << "Заработная плата: " << employee.salary << " рублей" << endl;
        cout << "------------------------------------------" << endl;
    }

    cout << "Сотрудник с самой низкой зарплатой: " << minSalaryName << " (" << minSalary << " рублей)" << endl;

    return 0;
}
