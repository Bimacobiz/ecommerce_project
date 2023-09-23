#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
private:
    std::string name;
    double unitPrice;
    int quantity;

public:
    Item();
    Item(const std::string& _name, double _unitPrice, int _quantity);

    std::string getName() const;
    void setName(const std::string& _name);

    double getUnitPrice() const;
    void setUnitPrice(double _unitPrice);

    int getQuantity() const;
    void setQuantity(int _quantity);

    bool operator==(const Item& other) const;

    friend std::istream& operator>>(std::istream& input, Item& item);
    friend std::ostream& operator<<(std::ostream& output, const Item& item);
};

#endif // ITEM_H
