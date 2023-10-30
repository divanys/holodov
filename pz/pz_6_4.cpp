//
// Created by divan on 10/30/23.
//
// Даны две строки текста. Определить сколько раз встречается каждый символ первой строки во второй строке.
// Например: Str1 : “xyz”; Str2: “x a d c x y x w”.
// Тогда “х” – встречается 3 раза “y”— встречается 1 раз, “z” — встречается 0 раз.
// Далее заменить все слова «компьютер» на слова «ПК» .

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;

    cout << "Введите первую строку: ";
    getline(cin, str1);
    cout << "Введите вторую строку: ";
    getline(cin, str2);

    // Создаем словарь для подсчета символов из первой строки во второй строке
    map<char, int> charCount;

    // Считаем символы из первой строки во второй строке
    for (char c : str1) {
        charCount[c] = count(str2.begin(), str2.end(), c);
    }

    // Выводим результат
    for (const auto& pair : charCount) {
        cout << "\"" << pair.first << "\" - встречается " << pair.second << " раз" << endl;
    }

    // Заменяем слова "компьютер" на "ПК" во второй строке
    size_t found = str2.find("компьютер");

    while (found != string::npos) {
        str2.replace(found, 18, "ПК"); // Заменяем 10 символов слова "компьютер" на "ПК"
        found = str2.find("компьютер", found + 2); // Начинаем поиск с позиции следующей после найденной
    }

    cout << "Вторая строка после замены: " << str2 << endl;

    cout << "Для завершения работы программы нажмите ENTER...";
    cin.get();

    return 0;
}
