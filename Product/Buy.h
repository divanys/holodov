//
// Created by divan on 11/7/23.
//

#ifndef HOLODOV_BUY_H
#define HOLODOV_BUY_H
// заголовочный фай производного класса Buy для класса Product 
#include "product.h"
 
class Buy : public Product // открытое наследование
{
private:
     int    sum; // количество покупаемого товара в шт.
     double sum_price, // цена за весь купленный товар   
            sum_weight; // общий вес
public:
    Buy(); // конструктор
 
    void setSum(const int &); // установить количество покупаемого товара
    int getSum() const; // возвратить количество покупаемого товара
 
    double getSumPrice() const; // возвратить цену за весь купленный товар
 
    double getSumWeight() const; // возвратить общий вес покупки
};

#endif //HOLODOV_BUY_H
