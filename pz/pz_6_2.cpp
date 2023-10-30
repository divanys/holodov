//
// Created by divan on 10/30/23.
//
//Исходный текст набран с ошибками: между некоторыми словами по несколько пробелов. Заменить в тексте подряд идущие пробелы одним пробелом.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string text;
    cout << "Введите входной текст для обработки: ";
    getline(cin, text);

    // Создаем новую строку, в которой будем удалять лишние пробелы
    string cleanedText;
    bool previousIsSpace = false; // Флаг, чтобы отслеживать предыдущий символ

    for (char c : text) {
        if (c == ' ' && previousIsSpace) {
            continue; // Пропускаем лишние пробелы
        } else {
            cleanedText += c;
            previousIsSpace = (c == ' ');
        }
    }

    cout << "После обработки текст имеет вид: " << cleanedText << endl;

    cout << "Для завершения работы программы нажмите ENTER...";
    cin.get();

    return 0;
}
