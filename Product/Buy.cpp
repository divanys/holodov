// Buy.cpp
#include "Buy.h"

Buy::Buy()
        : sum_price(0.0), sum_weight(0.0) {
}

void Buy::setProduct(const Product &product, int quantity) {
    products.emplace_back(product, quantity);
    sum_price += product.getPrice() * quantity;
    sum_weight += product.getWeight() * quantity;
}

const std::vector<std::pair<Product, int>>& Buy::getProducts() const {
    return products;
}

double Buy::getSumPrice() const {
    return sum_price;
}

double Buy::getSumWeight() const {
    return sum_weight;
}
