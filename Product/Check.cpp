// Check.cpp
#include "Check.h"

void Check::printCheck(const Buy &buy) const {
    std::cout << "Чек о покупке:\n";
    std::cout << "----------------------------------------\n";

    for (const auto &item : buy.getProducts()) {
        const Product &product = item.first;
        int quantity = item.second;

        std::cout << "Товар: " << product.getName() << "\n";
        std::cout << "Количество: " << quantity << " шт\n";
        std::cout << "Суммарная цена: " << product.getPrice() * quantity << " грн\n";
        std::cout << "Суммарный вес: " << product.getWeight() * quantity << " кг\n";
        std::cout << "----------------------------------------\n";
    }

    std::cout << "Товаров куплено: " << buy.getSumWeight() << " шт\n";
    std::cout << "На сумму: " << buy.getSumPrice() << " грн\n";
    std::cout << "Общий вес: " << buy.getSumWeight() << " кг\n";
    std::cout << "----------------------------------------\n";
}
