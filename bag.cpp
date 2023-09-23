#include "bag.h"

Bag::Bag() {}

void Bag::addItem(const Item& item) {
    items.push_back(item);
}

bool Bag::removeItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            items.erase(it);
            return true; // Item removed successfully
        }
    }
    return false; // Item not found
}

void Bag::clear() {
    items.clear();
}

const std::vector<Item>& Bag::getItems() const {
    return items;
}
