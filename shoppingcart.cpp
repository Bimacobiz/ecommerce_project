#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : totalPrice(0.0) {}

double ShoppingCart::getTotalPrice() const {
    return totalPrice;
}

void ShoppingCart::add(const Item& item) {
    items.push_back(item);
    totalPrice += item.getUnitPrice() * item.getQuantity();
}

void ShoppingCart::remove(int index) {
    if (index >= 0 && index < items.size()) {
        totalPrice -= items[index].getUnitPrice() * items[index].getQuantity();
        items.erase(items.begin() + index);
    }
}

void ShoppingCart::displayCart() const {
    if (items.empty()) {
        std::cout << "The shopping cart is empty." << std::endl;
    } else {
        std::cout << "=== Shopping Cart Contents ===" << std::endl;
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << "Item " << i + 1 << ":" << std::endl;
            std::cout << items[i] << std::endl;
        }
        std::cout << "Total Price: $" << getTotalPrice() << std::endl;
    }
}
