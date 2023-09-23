#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <algorithm> // Include the algorithm header for using std::remove

int main() {
    double totalCharge;
    ShoppingCart cart;
    std::cout << "Welcome to XXX SHOPPING CENTER." << std::endl;

    while (true) { // Start a loop for ordering
        std::vector<Item> items; // Create a vector to store the items for each order

        while (true) { // Start a loop for entering items
            std::string name;
            double unitPrice;
            int quantity;

            std::cout << "Enter the item you selected in the following format:" << std::endl;
            std::cout << "name unitPrice quantity" << std::endl;
            std::cout << "--> ";
            if (!(std::cin >> name >> unitPrice >> quantity)) {
                std::cout << "Invalid input. Please follow the correct format." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            Item newItem(name, unitPrice, quantity);
            items.push_back(newItem);

            char choice;
            std::cout << "Want to continue (y/n) --> ";
            std::cin >> choice;

            if (choice != 'y' && choice != 'Y') {
                break; // Finish entering items
            }
        }

        if (!items.empty()) {
            std::cout << "=== Receipt ===" << std::endl;
            std::cout << std::left << std::setw(20) << "Name"
                      << std::setw(15) << "Unit_Price"
                      << std::setw(10) << "Quantity"
                      << std::endl;
            std::cout << "-------------------------------------------------" << std::endl;

            double totalCharge = 0.0;

            for (const Item& item : items) {
                std::cout << std::left << std::setw(20) << item.getName()
                          << std::fixed << std::setprecision(2) << std::setw(15) << "$" << item.getUnitPrice()
                          << std::setw(10) << item.getQuantity()
                          << std::endl;
                totalCharge += item.getUnitPrice() * item.getQuantity();
            }

            std::cout << "-------------------------------------------------" << std::endl;
            std::cout << "The total charge is $" << totalCharge << std::endl;
            std::cout << "Thanks for shopping in XXX SHOPPING CENTER." << std::endl; // Added message
            std::cout << "-------------------------------------------------" << std::endl;

            char modifyChoice;
            std::cout << "Want to modify your order? (y/n) --> ";
            std::cin >> modifyChoice;

            if (modifyChoice == 'y' || modifyChoice == 'Y') {
                while (true) {
                    int action;
                    std::cout << "What do you want? Enter 1: add 2: remove 3: change quantity" << std::endl;
                    std::cout << "--> ";
                    std::cin >> action;

                    if (action == 1) { // Add an item
                        std::string name;
                        double unitPrice;
                        int quantity;

                        std::cout << "Enter the item to add in the following format:" << std::endl;
                        std::cout << "name unitPrice quantity" << std::endl;
                        std::cout << "--> ";
                        if (!(std::cin >> name >> unitPrice >> quantity)) {
                            std::cout << "Invalid input. Please follow the correct format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }

                        Item newItem(name, unitPrice, quantity);
                        items.push_back(newItem);

                        std::cout << "The item has been added." << std::endl; // Print confirmation
                    } else if (action == 2) { // Remove an item
                        std::string nameToRemove;
                        std::cout << "Enter the name of the item to remove:" << std::endl;
                        std::cout << "--> ";
                        std::cin >> nameToRemove;

                        // Use std::remove_if to remove the item by name
                        auto itemToRemove = std::remove_if(items.begin(), items.end(),
                            [nameToRemove](const Item& item) { return item.getName() == nameToRemove; });

                        if (itemToRemove != items.end()) {
                            items.erase(itemToRemove, items.end());
                            std::cout << "The item has been removed." << std::endl; // Print confirmation
                        } else {
                            std::cout << "No such item in your shopping cart!" << std::endl; // Item not found
                        }
                    } else if (action == 3) { // Change quantity
                        std::string nameToChange;
                        int newQuantity;

                        std::cout << "Enter the item to change as the following order:" << std::endl;
                        std::cout << "name quantity" << std::endl;
                        std::cout << "--> ";
                        if (!(std::cin >> nameToChange >> newQuantity)) {
                            std::cout << "Invalid input. Please follow the correct format." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }

                        // Find the item by name
                        auto itemToChange = std::find_if(items.begin(), items.end(),
                            [nameToChange](const Item& item) { return item.getName() == nameToChange; });

                        if (itemToChange != items.end()) {
                            itemToChange->setQuantity(newQuantity);
                            std::cout << "The quantity has been modified." << std::endl; // Print confirmation
                        } else {
                            std::cout << "No such item in your shopping cart!" << std::endl; // Item not found
                        }
                    } else {
                        std::cout << "Invalid choice. Please try again." << std::endl;
                    }

                    char modifyAgain;
                    std::cout << "Want to modify your order again? (y/n) --> ";
                    std::cin >> modifyAgain;

                    if (modifyAgain != 'y' && modifyAgain != 'Y') {
                        // Print the modified table and break
                        std::cout << "=== Modified Receipt ===" << std::endl;
                        std::cout << std::left << std::setw(20) << "Name"
                                  << std::setw(15) << "Unit_Price"
                                  << std::setw(10) << "Quantity"
                                  << std::endl;
                        std::cout << "-------------------------------------------------" << std::endl;

                        totalCharge = 0.0;

                        for (const Item& item : items) {
                            std::cout << std::left << std::setw(20) << item.getName()
                                      << std::fixed << std::setprecision(2) << std::setw(15) << "$" << item.getUnitPrice()
                                      << std::setw(10) << item.getQuantity()
                                      << std::endl;
                            totalCharge += item.getUnitPrice() * item.getQuantity();
                        }

                        std::cout << "-------------------------------------------------" << std::endl;
                        std::cout << "The total charge is $" << totalCharge << std::endl;
                        std::cout << "Thanks for shopping in XXX SHOPPING CENTER." << std::endl; // Added message
                        std::cout << "-------------------------------------------------" << std::endl;

                        break; // Exit the modification loop
                    }
                }
            } else {
                // Print the modified table and break
                std::cout << "=== Modified Receipt ===" << std::endl;
                std::cout << std::left << std::setw(20) << "Name"
                          << std::setw(15) << "Unit_Price"
                          << std::setw(10) << "Quantity"
                          << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;

                totalCharge = 0.0;

                for (const Item& item : items) {
                    std::cout << std::left << std::setw(20) << item.getName()
                              << std::fixed << std::setprecision(2) << std::setw(15) << "$" << item.getUnitPrice()
                              << std::setw(10) << item.getQuantity()
                              << std::endl;
                    totalCharge += item.getUnitPrice() * item.getQuantity();
                }

                std::cout << "-------------------------------------------------" << std::endl;
                std::cout << "The total charge is $" << totalCharge << std::endl;
                std::cout << "Thanks for shopping in XXX SHOPPING CENTER." << std::endl; // Added message
                std::cout << "-------------------------------------------------" << std::endl;

                break; // Exit the ordering loop
            }
        } else {
            std::cout << "The shopping cart is empty." << std::endl;
            char continueChoice;
            std::cout << "Want to continue your order or exit? (y/n) --> ";
            std::cin >> continueChoice;
            if (continueChoice != 'y' && continueChoice != 'Y') {
                // Print the modified table and break
                std::cout << "=== Modified Receipt ===" << std::endl;
                std::cout << std::left << std::setw(20) << "Name"
                          << std::setw(15) << "Unit_Price"
                          << std::setw(10) << "Quantity"
                          << std::endl;
                std::cout << "-------------------------------------------------" << std::endl;

                totalCharge = 0.0;

                for (const Item& item : items) {
                    std::cout << std::left << std::setw(20) << item.getName()
                              << std::fixed << std::setprecision(2) << std::setw(15) << "$" << item.getUnitPrice()
                              << std::setw(10) << item.getQuantity()
                              << std::endl;
                    totalCharge += item.getUnitPrice() * item.getQuantity();
                }

                std::cout << "-------------------------------------------------" << std::endl;
                std::cout << "The total charge is $" << totalCharge << std::endl;
                std::cout << "Thanks for shopping in XXX SHOPPING CENTER." << std::endl; // Added message
                std::cout << "-------------------------------------------------" << std::endl;

                break; // Exit the ordering loop
            }
        }
    }

    return 0;
}
