//
// Created by divan on 11/11/23.
//
#include <iostream>
#include <string>

class Auto
{
    friend void drive(Auto &);
    friend void setPrice(Auto &, int price);
public:
    Auto(std::string autoName, int autoPrice)
    {
    name = autoName;
    price = autoPrice;
    }
    std::string getName(){ return name; }
    int getPrice() { return price; }

private:
    std::string name; // название автомобиля
    int price; // цена автомобиля
};

void drive(Auto &a)
{
    std::cout << a.name << " is driven" << std::endl;
}
void setPrice(Auto &a, int price)
{
    if (price > 0)
    a.price = price;
}

int main()
{
    Auto tesla("Tesla", 5000);
    drive(tesla);
    std::cout << tesla.getName() << " : " << tesla.getPrice() << std::endl;
    setPrice(tesla, 8000);
    std::cout << tesla.getName() << " : " << tesla.getPrice() << std::endl;

    return 0;
}