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


#include "Point.h"

int main() {
    Point *p1 = new Point;
    Point *p2 = new Point;
    // p1.Point::x;
    // p1.x;

//    p1->init(3, 6);
    p2->init(3.4, 4.4);

    cout << "\np1\n";
    p1->print();
    cout << "\np2\n";
    p2->print();

    Point arr[10];
    arr[3] = *p1;

    cout << "\np1 (определяем объект в массиве ссылка)\n";
    arr[3].print();
    return 0;
}