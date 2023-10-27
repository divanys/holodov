//
// Created by divan on 9/6/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = 3.74e-2, y = -0.825, z = 0.16e2, a = 0, b = 0, c = 0, d = 0;
    a = (1 + pow(sin(x + y), 2));
    b = abs(x - ((2 * y) / (1 + pow(x, 2) * pow(y, 2))));
    c = pow(cos(atan(1. / z)), 2);
    d = a / b;
    s = d * pow(x, abs(y)) + c;
    cout << "s = " << s << endl;  // 1.98727
}

