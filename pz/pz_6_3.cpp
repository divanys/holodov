//
// Created by divan on 10/30/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string text;
    cout << "Введите входной текст для обработки: ";
    getline(cin, text);

    // Найдем индекс символа '*'
    size_t starIndex = text.find('*');

    if (starIndex == string::npos) {
        cout << "Символ '*' не найден в тексте." << endl;
    } else {
        // Создаем подстроку, содержащую слова перед '*'
        string substringBeforeStar = text.substr(0, starIndex);

        // Разбиваем подстроку на слова
        vector<string> words;
        size_t startPos = 0;
        size_t endPos = 0;

        while ((endPos = substringBeforeStar.find(' ', startPos)) != string::npos) {
            words.push_back(substringBeforeStar.substr(startPos, endPos - startPos));
            startPos = endPos + 1;
        }
        words.push_back(substringBeforeStar.substr(startPos));

        // Сортируем слова
        sort(words.begin(), words.end());

        // Обновляем оригинальную строку с отсортированными словами
        string sortedSubstringBeforeStar = words[0];
        for (int i = 1; i < words.size(); ++i) {
            sortedSubstringBeforeStar += " " + words[i];
        }
        text.replace(0, starIndex, sortedSubstringBeforeStar);

        cout << "После обработки текст имеет вид: " << text << endl;
    }

    return 0;
}
