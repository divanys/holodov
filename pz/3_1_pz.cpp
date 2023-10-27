//
// Created by divan on 9/6/23.
//

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a = 0.1;
    double b = 1.2;
    double h = 0.1;

    for (double x = a; x <= b; x += h) {
        double y = 0;
        for (int n = 1; n <= 20; n++) {
            y += pow(x, n-1) / (2*n + 1);
        }
        cout << "x = " << x << ", y = " << y << endl;
    }

    return 0;
}