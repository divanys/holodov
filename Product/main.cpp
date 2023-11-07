#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // Используем пространство имен std

class Product {
private:
    string name;
    double price;
    double weight;

public:
    Product(const string &name, double price, double weight)
            : name(name), price(price), weight(weight) {}

    const string &getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    double getWeight() const {
        return weight;
    }
};

class Buy : public Product {
private:
    int quantity;

public:
    Buy(const string &name, double price, double weight, int quantity)
            : Product(name, price, weight), quantity(quantity) {}

    int getQuantity() const {
        return quantity;
    }

    double getTotalPrice() const {
        return getPrice() * quantity;
    }
};

class Check : public Buy {
public:
    Check(const string &name, double price, double weight, int quantity)
            : Buy(name, price, weight, quantity) {}

    void printCheck() const {
        cout << left << setw(15) << "Товар" << left << setw(10) << "Цена" << left << setw(10) << "Вес" << left
             << setw(10) << "Количество" << left << setw(15) << "Итоговая цена" << endl;
        cout << left << setw(15) << getName() << left << setw(10) << getPrice() << left << setw(10) << getWeight()
             << left << setw(10) << getQuantity() << left << setw(15) << getTotalPrice() << endl;
    }
};

int main() {
    Check item("Молоко", 1.5, 1.0, 3);

    cout << "Информация о покупке:" << endl;
    item.printCheck();

    return 0;
}