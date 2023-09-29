//
// Created by divan on 9/29/23.
//

#include <iostream>

using namespace std;

int sum_by_value(int value) {
    value += value;
    return value;
}

int sum_by_reference(int &reference) {  // если const, то запрещаем менять reference
    reference += reference;
    return reference;
}

int sum_by_pointer(int *ptrvalue) {
    *ptrvalue += *ptrvalue;
    return *ptrvalue;
}

int main() {
    int value = 10;
    cout << "sum_by_value = " << sum_by_value(value) << endl;
    cout << "value = " << value << endl;
    cout << "sum_by_reference = " << sum_by_reference(value) << endl;
    cout << "value = " << value << endl;
    cout << "sum_by_pointer = " << sum_by_pointer(&value)
         << endl;  // если указатель терпит изменение, то и сама переменная тоже
    cout << "value = " << value << endl;

    return 0;
}

