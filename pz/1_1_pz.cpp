//
// Created by divan on 9/6/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = 14.26, y = -1.22, z = 3.5e-2, a = 0, b = 0, c = 0, d = 0;
    a = 2 * cos(x - (2. / 3.));
    b = (1./2.) + pow(sin(y), 2);
    c = (pow(z, 2) / (3. - pow(z, 2) / 5.));
    d = 1. + c;
    s = a / b * d;
    cout << "s = " << s << endl;  // 0.749155
    return 0;
}

