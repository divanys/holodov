//
// Created by divan on 10/27/23.
//
//код внизу эквивалентен этому:
//    Point p1;
//    p1.Point::x;
//    p1.x;
//    p1.init(3, 6);
//    p1.print();
//    return 0;
#include <iostream>

using namespace std;


#include "Point.h"
#include "Point.cpp"


int main() {
    Point p1;

    Point p2 = Point(3.0, 6.0);
    Point p3(3, 6);
    p3.print();
    Point p4 = p2;
    Point p5 = 5;
    p5.print();

    return 0;
}