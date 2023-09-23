#ifndef BAG_H
#define BAG_H

#include <vector>
#include "Item.h"

class Bag {
private:
    std::vector<Item> items;

public:
    Bag(); // Constructor
    void addItem(const Item& item);
    bool removeItem(const std::string& itemName);
    void clear();
    const std::vector<Item>& getItems() const;
};

#endif // BAG_H
