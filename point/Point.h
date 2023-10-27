//
// Created by divan on 10/27/23.
//

#ifndef HOLODOV_POINT_H
#define HOLODOV_POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    double x, y;
public:
    Point();
    Point(const Point&);
    Point(double, double );
    Point(double i);
    ~Point();
    void init(double xi, double yi);
    void print();
};


#endif //HOLODOV_POINT_H
