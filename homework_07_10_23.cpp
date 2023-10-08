//
// Created by divan on 10/7/23.
//
// дз от 07
//
// структура: студент
// поля:
//      имя
//      фамилия
//      группа
//      возраст
//      оценки(массив из 5 элементов)

//программа:
//      Пользователь вводит инфу руками из 5 структур типа студент
//      Вывести в табличной форме данный массив
//      Вывести на экран список студентов со ср оценкой больше 4
//      Упорядочить массив по возрасту
//      под звёздочкой:
//              Программа такая же про модели

#include<iostream>

using namespace std;

struct Marks {
    int DoSM, SysPro, Eng, PhyCul, DaDotPPI;
};

struct Student {
    char name[32];
    char lastName[32];
    char group[10];
    int age;
    Marks marks;
};

Student *AddStruct(Student *Obj, const int amount);

void setData(Student *Obj, const int amount);

void showData(const Student *Obj, const int amount);

void showDataAVG4(const Student *Obj, const int amount);

double avg(const Student *Obj, const int amount);

void swapStudents(Student &a, Student &b);

void sortByAge(Student *Obj, const int amount);

int main() {
    Student *OurStudent = 0;
    int studentAmount = 0;
    int YesOrNot = 0; //  продолжить или остановить ввод данных

    do {
        OurStudent = AddStruct(OurStudent, studentAmount);
        setData(OurStudent, studentAmount);
        studentAmount++;
        cout << "Продолжить ввод данных (1 - да, 0 - нет): ";
        cin >> YesOrNot;
        cin.get();  // очищение оператора cin
    } while (YesOrNot != 0);

    cout << "\nЗадание 2.\nВывести в табличной форме данный массив." << endl;
    showData(OurStudent, studentAmount);

    cout << "\nЗадание 3.\nВывести на экран список студентов со ср оценкой больше 4." << endl;
    showDataAVG4(OurStudent, studentAmount);

    cout << "\nЗадание 4.\nУпорядочить массив по возрасту." << endl;
    sortByAge(OurStudent, studentAmount); // Упорядочиваем по возрасту
    showData(OurStudent, studentAmount);

    delete[] OurStudent;
    return 0;
}

Student *AddStruct(Student *Obj, const int amount) {
    if (amount == 0) {
        Obj = new Student[amount + 1]; // выделение памяти для первой структуры
    } else {
        Student *tempObj = new Student[amount + 1];

        for (int i = 0; i < amount; i++) {
            tempObj[i] = Obj[i]; // копируем во временный объект
        }
        delete[] Obj;
        Obj = tempObj;
    }

    return Obj;
}

void setData(Student *Obj, const int amount) {
    cout << "Имя: ";
    cin.getline(Obj[amount].name, 32);
    cout << "Фамилия: ";
    cin.getline(Obj[amount].lastName, 32);
    cout << "Группа студента: ";
    cin.getline(Obj[amount].group, 10);
    cout << "Возраст студента: ";
    cin >> Obj[amount].age;
    cout << "Введите оценки студента: " << endl;
    cout << "1. Development of software modules: ";
    cin >> Obj[amount].marks.DoSM;
    cout << "2. System programming: ";
    cin >> Obj[amount].marks.SysPro;
    cout << "3. English: ";
    cin >> Obj[amount].marks.Eng;
    cout << "4. Physical Culture: ";
    cin >> Obj[amount].marks.PhyCul;
    cout << "5. Design and development of the PP interface: ";
    cin >> Obj[amount].marks.DaDotPPI;

    cin.get();
    cout << endl;
}

void showData(const Student *Obj, const int amount) {
    cout << "№  " << "Имя\t\t" << "Фамилия\t\t" << "Группа\t" << "Возраст\t" << "DoSM\t"
         << "SysPro\t" << "Eng\t" << "PhyCul\t"
         << "DaDotPPI\t" << endl;
    cout << "========================================================="
            "==============================================" << endl;

    for (int i = 0; i < amount; i++) {
        cout << i + 1 << "  " << Obj[i].name << "\t" << Obj[i].lastName << "\t\t" << Obj[i].group << '\t' << Obj[i].age
             << '\t' << Obj[i].marks.DoSM << '\t' << Obj[i].marks.SysPro << '\t' << Obj[i].marks.Eng << '\t'
             << Obj[i].marks.PhyCul << '\t' << Obj[i].marks.DaDotPPI << endl;
    }
}

// Вывести на экран список студентов со ср оценкой больше 4
double avg(const Marks &marks) {
    double sum = marks.DoSM + marks.SysPro + marks.Eng + marks.PhyCul + marks.DaDotPPI;

    return sum / 5;
}

void showDataAVG4(const Student *Obj, const int amount) {
    int YorN = 0;

    cout << "№  " << "Имя\t\t" << "Фамилия\t\t" << "Группа\t" << "Возраст\t" << "DoSM\t"
         << "SysPro\t" << "Eng\t" << "PhyCul\t"
         << "DaDotPPI\t" << endl;
    cout << "========================================================="
            "==============================================" << endl;

    for (int i = 0; i < amount; i++) {
        if (avg(Obj[i].marks) > 4.0) {
            cout << i + 1 << "  " << Obj[i].name << "\t" << Obj[i].lastName << "\t\t" << Obj[i].group << '\t'
                 << Obj[i].age
                 << '\t' << Obj[i].marks.DoSM << '\t' << Obj[i].marks.SysPro << '\t' << Obj[i].marks.Eng << '\t'
                 << Obj[i].marks.PhyCul << '\t' << Obj[i].marks.DaDotPPI << endl;

            YorN++;
        }
    }

    if (YorN == 0) {
        cout << "Таких студентов не найдено!" << endl;
    }
}

// Упорядочить массив по возрасту
void swapStudents(Student &a, Student &b) {  // просто обмен данными
    Student temp = a;
    a = b;
    b = temp;
}

void sortByAge(Student *Obj, const int amount) {  // сортировка пузырьком помогает)
    for (int i = 0; i < amount - 1; i++) {
        for (int j = 0; j < amount - i - 1; j++) {
            if (Obj[j].age > Obj[j + 1].age) {
                swapStudents(Obj[j], Obj[j + 1]);
            }
        }
    }
}

