//
// Created by divan on 11/7/23.
//

#ifndef HOLODOV_CHECK_H
#define HOLODOV_CHECK_H
// заголовочный файл производного класса Check для класса Buy
#include "buy.h"
class Check :public Buy// открытое наследование
{
public:
void printProductInfo() {
    cout <<"Товар: " << getName() << endl;
    cout <<"Цена " << getPrice() <<" грн\n";
    cout <<"Вес: " << getWeight() <<" кг\n\n";
}

void printBuyInfo()
{
cout <<"Товара куплено: " << getSum() <<" шт\n";
cout <<"На сумму " << getSumPrice() <<" грн\n";
#endif //HOLODOV_CHECK_H
// заголовочный файл производного класса Check для класса Buy
 
#include "buy.h"
 
class Check : public Buy // открытое наследование
{
public:
void printProductInfo()
{
    cout << "Товар: " << getName()   << endl;
    cout << "Цена:  "  << getPrice()  << " грн\n";
    cout << "Вес:   "   << getWeight() << " кг\n\n";
}
 
    void printBuyInfo()
    {
        cout << "Товара куплено: " << getSum() << " шт\n";
        cout << "На сумму:       " << getSumPrice() << " грн\n";
        cout << "Общий вес:      " << getSumWeight() << " кг\n\n";
    }
 
};
#endif CHECK_H
