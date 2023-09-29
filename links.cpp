//
// Created by divan on 9/29/23.
//


#include <iostream>

using namespace std;


int main() {
    int value = 15;
    int &reference = value; // ссылка

    cout << "value = " << value << "\nreference  = " << reference << endl;
    reference += 15; // меняется и value

    cout << "value = " << value << "\nreference  = " << reference << endl;
    return 0;
}
