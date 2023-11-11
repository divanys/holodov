// Product.h
#ifndef HOLODOV_PRODUCT_H
#define HOLODOV_PRODUCT_H

#include <cstring>
#include <iostream>

class Product {
private:
    char name[50];
    double price, weight;
public:
    Product();

    void setName(const char *);

    const char *getName() const;

    void setPrice(const double &);

    double getPrice() const;

    void setWeight(const double &);

    double getWeight() const;

    void printProductInfo() const;
};

#endif //HOLODOV_PRODUCT_H
