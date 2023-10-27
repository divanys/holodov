//
// Created by divan on 10/27/23.
//

#include <iostream>

using namespace std;

#include "Point.h"

Point::Point() { x = 0.0, y = 0.0; }

void Point::init(double xi, double yi) {
    x = xi;
    y = yi;
}

void Point::print() {
    cout << "x = " << x << ", y = " << y;
}

Point::Point(const Point &other) {
    x = other.x;
    y = other.y;
}

Point::Point(double xi, double yi) {
    x = xi;
    y = yi;
}

Point::Point(double i) {
    x = i;
    y = i;
}

Point::~Point() {
    cout << "Obj del\n" ;
}