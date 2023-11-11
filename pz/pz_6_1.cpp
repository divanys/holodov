//
// Created by divan on 10/30/23.
//
// Разработка программ на языке С++ для обработки строк.
// Пользователь вводит текст. Вывести исходный текст, заменив в нем слово <Pascal> на <C++>,
// подсчитав их количество. Вычислить количество слов <компьютер>.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string text;
    cout << "Введите входной текст для обработки: ";
    getline(cin, text);

    string PASCAL = "pascal";
    const string CPP = "C++";

    transform(text.begin(), text.end(), text.begin(), ::tolower); // Приведение к нижнему регистру

    size_t index_find_word = text.find(PASCAL);

    while (index_find_word != string::npos) {
        text.replace(index_find_word, PASCAL.size(), CPP);
        index_find_word = text.find(PASCAL, index_find_word + CPP.size());
    }

    string KOMPUTER = "komputer";

    transform(text.begin(), text.end(), text.begin(), ::tolower);
    transform(KOMPUTER.begin(), KOMPUTER.end(), KOMPUTER.begin(), ::tolower);

    index_find_word = text.find(KOMPUTER);

    int count_komputer = 0;

    while (index_find_word != string::npos) {
        count_komputer++;
        index_find_word = text.find(KOMPUTER, index_find_word + KOMPUTER.size());
    }

    cout << "Текст после обработки: " << text << endl;
    cout << "Количество слов komputer: " << count_komputer << endl;

    cout << endl << "Для завершения работы программы нажмите ENTER...";
    cin.get();

    return 0;
}