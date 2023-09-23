#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "bagInterface.h"
#include "Item.h"
#include <vector>

class ShoppingCart {
private:
    std::vector<Item> items;
    double totalPrice;

public:
    ShoppingCart();
    double getTotalPrice() const;
    void add(const Item& item);
    void remove(int index);

    void displayCart() const;
};

#endif // SHOPPINGCART_H
