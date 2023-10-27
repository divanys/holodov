//
// Created by divan on 9/6/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = -15.246, y = 4.642e-2, z = 21, a = 0, b = 0, c = 0, d = 0;
    d = -1 * sqrt(abs(x));
    a = log(pow(y, d));
    b = x - (y / 2.);
    c = pow(sin(atan(z)), 2);
    s = a * b + c;
    cout << "s = " << s << endl;  // -182.038
}

