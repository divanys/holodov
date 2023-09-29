//
// Created by divan on 9/29/23.
//

#include <iostream>

using namespace std;


int main() {
    int var1 = 123, var2 = 99;
    int *ptrvar1 = &var1, *ptrvar2 = &var2;

    cout << "&var1 = " << var1 << endl;
    cout << "&var2 = " << var2 << endl;
    cout << "ptrvar1 = " << ptrvar1 << endl;
    cout << "ptrvar2 = " << ptrvar2 << endl;

    if (ptrvar1 > ptrvar2) {
        cout << "ptrvar1 > ptrvar2" << endl;
    }

    if (*ptrvar1 > *ptrvar2) {
        cout << "*ptrvar1 > *ptrvar2" << endl;
    }
    return 0;
}

