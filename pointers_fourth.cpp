//
// Created by divan on 9/29/23.
//

#include <iostream>

using namespace std;


int main() {
    int var1 = 123;
    int *ptrvar1 = &var1;
    int **ptr_ptrvar1 = &ptrvar1;
    int ***ptr_ptr_ptrvar1 = &ptr_ptrvar1;
    cout << "&var1 = " << var1 << endl;
    cout << "ptrvar1 = " << *ptrvar1 << endl;
    cout << "**ptr_ptrvar1 = " << **ptr_ptrvar1 << endl;
    cout << "***ptr_ptr_ptrvar1 = " << ***ptr_ptr_ptrvar1 << endl;
    cout << "***ptr_ptr_ptrvar1 -> **ptr_ptrvar1 -> *ptrvar1 -> var1" << var1<< endl;
    cout << &ptr_ptr_ptrvar1 << " -> " << &ptr_ptrvar1 << " -> " << &ptrvar1 << " -> " << &var1 << " -> " << var1 << endl;

    return 0;
}

