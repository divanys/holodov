// main.cpp
#include "Product.h"
#include "Buy.h"
#include "Check.h"
#include <iostream>

int main() {
    const int PRODUCT_COUNT = 3;

    // Создаем массив товаров
    Product products[PRODUCT_COUNT];
    products[0].setName("Молоко");
    products[0].setPrice(20.0);
    products[0].setWeight(1.0);

    products[1].setName("Хлеб");
    products[1].setPrice(10.0);
    products[1].setWeight(0.5);

    products[2].setName("Батон");
    products[2].setPrice(15.0);
    products[2].setWeight(0.7);

    // Выводим информацию о товарах
    std::cout << "Информация о товарах:\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Имя товара\t\tЦена\tВес\n";
    std::cout << "----------------------------------------\n";
    for (auto &product : products) {
        std::cout << product.getName() << "\t\t\t" << product.getPrice() << "\t" << product.getWeight() << "\n";
    }
    std::cout << "----------------------------------------\n";

    // Создаем объект Buy для покупок
    Buy buy;

    // Покупаем товары
    buy.setProduct(products[0], 3); // 3 молока
    buy.setProduct(products[1], 1); // 1 хлеб
    buy.setProduct(products[2], 2); // 2 батона

    // Выводим информацию о покупке (чек)
    Check check;
    check.printCheck(buy);

    return 0;
}