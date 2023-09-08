//
// Created by divan on 9/6/23.
//

#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double s = 0, x = 0, y = 0, a = 0, b = 0, c = 0, d = 0;
    cout << "Введите x" << endl;
    cin >> x;
    cout << "Введите y" << endl;
    cin >> y;
    cout << "Введите d" << endl;
    cin >> d;
    if ((x * y) < 10 && (x * y) > 1) {
        for (int i = 1; i <= 20; i++) {
            s += sin(25. - ((pow(d, 2) * pow(i, 1/4)) / (sqrt(x) - pow(y, 2))));
        }
        cout << "1: " << s << endl;
    } else if ((x * y) > 11 && (x * y) < 40) {
        s = exp(abs(pow((x - pow(y, 2)), 1. / 4.) - (pow(d, 2) / (2 * sin(y)))));
        cout << "2: " << s << endl;
    } else {
        for (int i = 1; i <= 40; i++) {
            s += (cos(pow(pow(x - d + pow(y, 2), 4), 1./6.)) - pow(i, 4)) / (cbrt(pow(sin(y), 8) + i));
        }
        cout << "3: " << s << endl;
    }

}

