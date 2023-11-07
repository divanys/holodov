//
// Created by divan on 11/7/23.
//
#include "stdafx.h"
 
#include "product.h"
 
#include <cstring> // прототип strcpy()
 
Product::Product() // конструктор
    : price(0.0), weight(0.0)
{
    for (int counter = 0; counter < 50; counter++)
        name[counter] = '\0';
}
 
void Product::setName(const char *name_product) // установить имя товара
{
    strcpy(name, name_product); // имя товара копируем в элемент данных класса
}
 
const char *Product::getName() const // возвратить имя товара
{
    return name;
}
 
void Product::setPrice(const double & pr) // установить стоимость 1 ед. товара
{
    price = (pr >= 0 ? pr : 0);
}
 
double Product::getPrice() const // возвратить стоимость 1 ед. товара
{
    return price;
}
 
void Product::setWeight(const double & wgh) // установить вес товара
{
    weight = wgh;
}
 
double Product::getWeight() const
{
    return weight;
}