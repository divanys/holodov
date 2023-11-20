//
// Created by divan on 11/20/23.
//
// Определить класс список элементов.
// В определение класса включить два конструктора для определения списка по его размеру и путем
// копирования другого списка.  Предусмотреть функции
// формирования нового списка из элементов, входящих только в один из двух других списков и вычисления
// суммы элементов списков.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>  // Для использования функций rand() и srand()

using namespace std;

class ElementList {
private:
    vector<int> elements;

public:
    // Конструктор для определения списка по его размеру
    ElementList(int size) {
        srand(time(0));  // генератор случайных чисел
        elements.resize(size);

        // Заполнение вектора случайными значениями от 1 до 10
        for (int &elem: elements) {
            elem = rand() % 10 + 1;
        }
    }

    // Конструктор для копирования другого списка
    ElementList(const vector<int> &other_list) {
        elements = other_list;
    }

    // Функция для формирования нового списка из элементов, входящих только в один из двух списков
    ElementList getUniqueElements(const ElementList &other_list) const {
        vector<int> unique_elements;

        for (int elem: elements) {
            if (find(other_list.elements.begin(), other_list.elements.end(), elem) == other_list.elements.end()) {
                unique_elements.push_back(elem);
            }
        }

        for (int elem: other_list.elements) {
            if (find(elements.begin(), elements.end(), elem) == elements.end()) {
                unique_elements.push_back(elem);
            }
        }

        return ElementList(unique_elements);
    }

    // Функция для вычисления суммы элементов списка
    int sumOfElements() const {
        int sum = 0;
        for (int elem: elements) {
            sum += elem;
        }
        return sum;
    }

    // Функция для вывода элементов списка
    void displayElements() const {
        for (int elem: elements) {
            cout << elem << " ";
        }
        cout << endl;
    }
};

int main() {
    ElementList list1(5);  // Создание списка по размеру
    ElementList list2({1, 2, 3, 4, 5});  // Копирование другого списка

    cout << "List 1 elements: ";
    list1.displayElements();
    cout << "List 2 elements: ";
    list2.displayElements();

    ElementList list3 = list1.getUniqueElements(list2);  // Получение списка уникальных элементов
    cout << "Unique elements: ";
    list3.displayElements();

    int sumOfList1 = list1.sumOfElements();  // Вычисление суммы элементов первого списка
    int sumOfList2 = list2.sumOfElements();  // Вычисление суммы элементов второго списка

    cout << "Sum of List 1: " << sumOfList1 << endl;
    cout << "Sum of List 2: " << sumOfList2 << endl;

    return 0;
}

