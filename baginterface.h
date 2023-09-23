#ifndef BAG_INTERFACE_H
#define BAG_INTERFACE_H

#include <vector>
#include "Item.h"

class BagInterface {
public:
    virtual void addItem(const Item& item) = 0;
    virtual bool removeItem(const std::string& itemName) = 0;
    virtual void clear() = 0;
    virtual const std::vector<Item>& getItems() const = 0;
    virtual ~BagInterface() {} // Virtual destructor for interface
};

#endif // BAG_INTERFACE_H
