//
// Created by divan on 10/27/23.
//

#include "Point.h"
Point::Point() { x = 0.0, y = 0.0; }

void Point::init(double xi, double yi) {
    x = xi;
    y = yi;
}
void Point::print() {
    cout << "x = " << x << ", y = " << y;
}