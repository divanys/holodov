// Product.cpp
#include "Product.h"

Product::Product()
        : price(0.0), weight(0.0) {
    for (int counter = 0; counter < 50; counter++)
        name[counter] = '\0';
}

void Product::setName(const char *name_product) {
    strcpy(name, name_product);
}

const char *Product::getName() const {
    return name;
}

void Product::setPrice(const double &pr) {
    price = (pr >= 0 ? pr : 0);
}

double Product::getPrice() const {
    return price;
}

void Product::setWeight(const double &wgh) {
    weight = wgh;
}

double Product::getWeight() const {
    return weight;
}

void Product::printProductInfo() const {
    std::cout << "Товар: " << getName() << "\n";
    std::cout << "Цена " << getPrice() << " грн\n";
    std::cout << "Вес: " << getWeight() << " кг\n\n";
}
