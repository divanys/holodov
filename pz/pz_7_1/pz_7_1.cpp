//
// Created by divan on 10/30/23.
//
// использовать стандартные потоковые классы для решения задачи
// Дан файл f, компоненты которого являются целыми числами.
// Записать в файл g все четные числа исходного файла, в файл h – все нечетные.
// Порядок следования чисел сохраняется. Записать в файл g и h комментарии.

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("./pz/pz_7_1/f.txt");
    ofstream evenFile("./pz/pz_7_1/g.txt");
    ofstream oddFile("./pz/pz_7_1/h.txt");

    if (!inputFile.is_open() || !evenFile.is_open() || !oddFile.is_open()) {
        cerr << "Не удалось открыть один из файлов." << endl;
        return 1;
    }

    int number;
    while (inputFile >> number) {
        if (number % 2 == 0) {
            evenFile << number << endl;
        } else {
            oddFile << number << endl;
        }
    }

    // Записываем комментарии в файлы g и h
    evenFile << "Четные числа из файла f." << endl;
    oddFile << "Нечетные числа из файла f." << endl;

    // Закрываем все файлы
    inputFile.close();
    evenFile.close();
    oddFile.close();

    cout << "Четные и нечетные числа успешно записаны в файлы g и h." << endl;

    return 0;
}
