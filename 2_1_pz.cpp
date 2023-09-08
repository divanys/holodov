//
// Created by divan on 9/6/23.
//

#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double x, y;
    cout << "Введите значения x и y: ";
    cin >> x >> y;
    double res1, res2, res3;
    if (x > abs(y)) {
        res1 = 2 * pow(x, 3) + 3 * pow(y, 2);
    } else {
        res1 = 0;
    }
    if (x > 3 && x < abs(y)) {
        res2 = abs(x - y);
    } else {
        res2 = 0;
    }
    if (x < abs(y)) {
        res3 = pow(3, sqrt(abs(x - y)));
    } else {
        res3 = 0;
    }

    cout << "Результаты:" << endl;
    cout << "2x^3 + 3y^2 = " << res1 << endl;
    cout << "|x - y| = " << res2 << endl;
    cout << "3^(sqrt|x - y|) = " << res3 << endl;
}