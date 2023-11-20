//
// Created by divan on 11/20/23.
//
#include "array.h"
#include <iostream>
#include <iomanip>  // для манипулятора setw

using namespace std;

Array::Array() {  // конструктор по умолчанию, без параметров
    size = 10;  // по умолчанию размер массива = 10 элементов
    ptr = new int[size];  // выделить место в памяти для массива

    for (int i = 0; i < size; i++) {  // обнуляем массив
        ptr[i] = 0;
    }
}

Array::Array(int arraySize) {  // конструктор с параметрами
    // если значение параметра больше 0, присвоить size значение arraySize, иначе -
    size = (arraySize > 0 ? arraySize : 10);
    ptr = new int[size];  // выделить место в памяти для массива

    for (int i = 0; i < size; i++) {  // обнуляем массив
        ptr[i] = 0;
    }
}

Array::Array(const Array &arrayToCopy)  // конструктор копии
        : size(arrayToCopy.size) {  // инициализатор размера массива

    ptr = new int[size];  // выделить место в памяти для массива

    for (int i = 0; i < size; i++) {
        ptr[i] = arrayToCopy.ptr[i];  // заполняем массив значениями массива arrayToCopy
    }
}

Array::~Array() {
    delete[] ptr;
}

int Array::getSize() const {  // возвратить количество элементов массива
    return size;
}

// перегруженный оператор ввода, для ввода значений массива с клавиатуры
istream &operator>>(istream &input, Array &obj) {

    for (int i = 0; i < obj.size; i++) {
        input >> obj.ptr[i]; // заполняем массив объекта obj
    }
    return input;  // позволяет множественный ввод, типа cin >> x >> у >> z >> …
}

// перегруженный оператор вывода для класса Array (вывод элементов массива на экран)
ostream &operator<<(ostream &output, const Array &obj) {
    for (int i = 0; i < obj.size; i++) {
        output << setw(5)  // под каждое число выделяется 5 позиций
               << obj.ptr[i];
    }

    output << std::endl;  // перенос маркера на новую строку

    return output;  // позволяет множественный вывод, типа cout << x << y << z << …
}

void Array::setArray() {  // заполнение массива
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];  // ввод элемента массива с клавиатуры
    }
}

void Array::getArray() {  // вывод массива
    for (int i = 0; i < size; i++) {
        cout << setw(5) << ptr[i];  // вывод элементов массива на экран
        cout << std::endl;  // новая строка
    }
}

const Array &Array::operator=(const Array &right) {  // оператор присваивания
    if (&right != this) {  // чтобы не выполнялось самоприсваивание
        if (size != right.size) {
            delete[] ptr;  // освободить пространство
            size = right.size;  // установить нужный размер массива
            ptr = new int[size];  // выделить память под копируемый массив
        }
        for (int i = 0; i < size; i++) {
            ptr[i] = right.ptr[i];  // скопировать массив
        }
    }
    return *this;  // разрешает множественное присваивание, например x =
}

bool Array::operator==(const Array &right) const {  // оператор сравнения
    if (size != right.size) {
        return false;  // массивы с разным количеством элементов
    }

    for (int i = 0; i < size; i++) {
        if (ptr[i] != right.ptr[i]) {  // массивы не равны
            return false;
        }
    }
    return true;  // массивы равны
}

int &Array::operator[](int subscript) {

    if (subscript < 0 || subscript >= size) {
        std::cerr << "\n Ошибка индекса: " << subscript << std::endl;
        exit(1); // завершить работу программы, неправильный индекс
    }

    return ptr[subscript]; // возврат ссылки на элемент массива
}

Array Array::operator+(const Array &right) {
    if (size != right.size) {
        cout << "Mассивы разного размера!\n";
        exit(1);  // завершить работу программы
    }

    Array result(size);
    for (int i = 0; i < size; i++) {
        result.ptr[i] = ptr[i] + right.ptr[i];
    }
    return result;  // вернуть сумму
}

Array &Array::operator+=(const int &number) { // оператор добавления элемента в конец массива
    Array result(size);
    result = *this;  // временно сохраним текущий массив

    delete[] ptr;  // освобождаем память

    size = size + 1;  // увеличиваем размер массива на 1
    ptr = new int[size];  // выделяем память

    for (int i = 0; i < (size - 1); i++) {
        ptr[i] = result.ptr[i];  // скопировать массив
    }

    ptr[size - 1] = number;  // добавляем число в конец массива
    return *this;  // каскадный вызов перегруженного оператора
}

Array &Array::operator-(const int &key) {  // оператор удаления элемента по ключу
    int counterKey = 0; // счетчик найденных ключевых элементов

    // определяем количество элементов, которые необходимо удалить
    for (int i = 0; i < size; i++) {

        if (ptr[i] == key) {
            counterKey++;
        }
    }

    Array temp(size);
    temp = *this; // сохраняем текущий массив во временный объект

    delete[] ptr; // освобождаем память

    size = size - counterKey;  // переопределяем размер
    ptr = new int[size];
    int counter = 0, i = 0;

    while (counter < size) {

        if (temp[counter] != key) {
            ptr[i] = temp.ptr[counter]; // скопировать массив
            i++;
        }

        counter++;
    }

    return *this;
}

int Array::search(const int key) const {  // поиск по ключу
    for (int i = 0; i < size; i++) {
        if (key == ptr[i]) {  // поиск по ключу
            return (i + 1);  //позиция искомого элемента
        }
    }
    return -1;
}

void Array::choicesSort() {  // сортировка выбором
    for (int repeat_counter = 0; repeat_counter < size; repeat_counter++) {
        int temp = ptr[0]; // временная переменная для хранения значения перестановки
        for (int element_counter = repeat_counter + 1; element_counter < size; element_counter++) {
            if (ptr[repeat_counter] > ptr[element_counter]) {
                temp = ptr[repeat_counter];
                ptr[repeat_counter] = ptr[element_counter];
                ptr[element_counter] = temp;
            }
        }
    }
}
