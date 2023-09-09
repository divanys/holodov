//
// Created by divan on 9/9/23.
//
#include <iostream>
using namespace std;

int main() {
    int a, b;
    char znak;
    cout << "Введите месяц и год: ";
    cin >> a >> znak >> b;
    switch (znak) {
        case '+': cout << "a + b is " << a + b << endl;
            break;
        case '-': cout << "a - b is " << a - b << endl;
            break;
        case '*': cout << "a * b is " << a * b << endl;
            break;
        case '/': cout << "a / b is " << a / b << endl;
            break;
        default: cout << "error";
    }
    return 0;
}
