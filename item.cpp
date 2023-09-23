#include "Item.h"

Item::Item() : name(""), unitPrice(0.0), quantity(0) {}

Item::Item(const std::string& _name, double _unitPrice, int _quantity)
    : name(_name), unitPrice(_unitPrice), quantity(_quantity) {}

std::string Item::getName() const { return name; }
void Item::setName(const std::string& _name) { name = _name; }

double Item::getUnitPrice() const { return unitPrice; }
void Item::setUnitPrice(double _unitPrice) { unitPrice = _unitPrice; }

int Item::getQuantity() const { return quantity; }
void Item::setQuantity(int _quantity) { quantity = _quantity; }

bool Item::operator==(const Item& other) const {
    return (name == other.name) && (unitPrice == other.unitPrice) && (quantity == other.quantity);
}

std::istream& operator>>(std::istream& input, Item& item) {
    std::cout << "Enter item name: ";
    input >> item.name;
    std::cout << "Enter unit price: ";
    input >> item.unitPrice;
    std::cout << "Enter quantity: ";
    input >> item.quantity;
    return input;
}

std::ostream& operator<<(std::ostream& output, const Item& item) {
    output << "Item Name: " << item.name << std::endl;
    output << "Unit Price: $" << item.unitPrice << std::endl;
    output << "Quantity: " << item.quantity << std::endl;
    return output;
}
