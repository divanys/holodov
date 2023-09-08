//
// Created by divan on 9/6/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = 0.4e4, y = -0.875, z = 0.475e-3, a = 0, b = 0, c = 0, d = 0;
    a = abs(cos(x) - cos(y));
    b = pow(a, (1. + 2. * pow(sin(y), 2)));
    c = 1 + z + (pow(z, 2) / 2.) + (pow(z, 3) / 3) + (pow(z, 4) / 4);
    s = b * c;
    cout << "s = " << s << endl;  // 1.98727
}

