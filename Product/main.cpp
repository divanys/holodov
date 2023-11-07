//
// Created by divan on 11/7/23.
//
#include "Product.h"
#include "Buy.h"
#include "Check.h"
#include <iostream>

using namespace std;

int main() {
    // Создаем объект товара
    Product product;
    product.setName("Продукт 1");
    product.setPrice(10.5);
    product.setWeight(0.5);

    // Создаем объект покупки
    Buy buy;
    buy.setSum(3); // Покупаем 3 единицы товара

    // Выводим информацию о товаре и покупке
    cout << "Информация о товаре:" << endl;
    cout << "Имя: " << product.getName() << endl;
    cout << "Цена: " << product.getPrice() << " грн" << endl;
    cout << "Вес: " << product.getWeight() << " кг" << endl << endl;

    cout << "Информация о покупке:" << endl;
    cout << "Количество: " << buy.getSum() << " шт" << endl;
    cout << "Общая цена: " << buy.getSumPrice() << " грн" << endl;
    cout << "Общий вес: " << buy.getSumWeight() << " кг" << endl << endl;

    // Создаем объект чека и выводим информацию о покупке и товаре
    Check check;
    check.printProductInfo();
    check.printBuyInfo();

    return 0;
}
