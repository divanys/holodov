//
// Created by divan on 9/6/23.
//
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = -4.5, y = 0.75e-4, z = -0.845e2, a = 0, b = 0, c = 0, d = 0;
    a = cbrt(9. + pow((x - y), 2));
    b = pow(x, 2) + pow(y, 2) + 2.;
    c = exp(abs(x - y));
    d = pow(tan(z), 3);
    s = (a / b) - (c * d);
    cout << "s = " << s << endl;  // -3.23765
}

