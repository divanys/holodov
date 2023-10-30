//
// Created by divan on 10/30/23.
//
// Разработка программ на языке С++ для обработки строк.
// Пользователь вводит текст. Вывести исходный текст, заменив в нем слово <Pascal> на <C++>,
// подсчитав их количество. Вычислить количество слов <компьютер>.

#include <iostream>
#include <string>

using namespace std;

int main() {

    string text;
    cout << "Введите входной текст для обработки: ";
    getline(cin, text);

    const string PASKAL = "Pascal";
    const string CIKRESTIKKRESTIK = "C++";

    size_t index_find_word = text.find(PASKAL);

    while (index_find_word < text.size()) {
        text.erase(index_find_word, PASKAL.size());
        text.insert(index_find_word, CIKRESTIKKRESTIK);
        index_find_word = text.find(PASKAL);
    }

    const string KOMPUTER = "komputer";

    index_find_word = text.find(KOMPUTER);

    while (index_find_word < text.size()) {
        text.erase(index_find_word, KOMPUTER.size());
        index_find_word = text.find(KOMPUTER);
    }

    cout << "Текст после обработки: " << text;

    fflush(stdin);

    cout << endl << endl << "Для завершения работы программы нажмите ENTER...";
    cin.get();

    return 0;
}
