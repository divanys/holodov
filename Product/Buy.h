// Buy.h
#ifndef HOLODOV_BUY_H
#define HOLODOV_BUY_H

#include <vector>
#include "Product.h"

class Buy {
private:
    std::vector<std::pair<Product, int>> products; // пара: продукт и количество
    double sum_price; // суммарная цена
    double sum_weight; // суммарный вес
public:
    Buy();

    void setProduct(const Product &, int);

    const std::vector<std::pair<Product, int>>& getProducts() const;

    double getSumPrice() const;

    double getSumWeight() const;
};

#endif //HOLODOV_BUY_H
