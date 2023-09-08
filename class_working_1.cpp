//
// Created by divan on 9/6/23.
//

//
// Created by divan on 9/6/23.
//

#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int digit = 0;
    char exit = 'y';
    for (;;)
    {
        cout << "Введите чиселко: ";
        cin >> digit;
        cout << digit << " = " << pow(digit, 2);
        cout << "\n Продолжить ввод чисел -y. Выйти -n" << endl;
        cin >> exit;
        if (exit != 'y' && exit != 'Y')
            break;
    }
}

