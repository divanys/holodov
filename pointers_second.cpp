//
// Created by divan on 9/29/23.
//

#include <iostream>

using namespace std;


int main() {
    int var = 123;
    int *ptrvar = &var;
    cout << "&var = " << &var << endl;
    cout << "ptrvar = " << ptrvar << endl;
    cout << "var = " << var << endl;
    cout << "*ptrvar = " << *ptrvar << endl;  // разыменовываем указатель

    return 0;
}

