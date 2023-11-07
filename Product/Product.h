//
// Created by divan on 11/7/23.
//
// заголовочный файл базового класса Product для всех классов
#ifndef HOLODOV_PRODUCT_H
#define HOLODOV_PRODUCT_H

class Product {
private:
    char name[50];// имя товара
    double price,  // цена
    weight;  // вес 1 ед.
public:
    Product();

    void setName(const char *);

    const char *getName() const;

    void setPrice(const double &);  // установить цену товара
    double getPrice() const;  // возвратить цену товара

    void setWeight(const double &);  // установить вес 1 ед. товара
    double getWeight() const;  // возвратить вес 1 ед. товара
};

#endif //HOLODOV_PRODUCT_H
