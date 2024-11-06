// write a program in c++ to implement a shoping list .
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ShoppingList {
private:
    vector<pair<string, double>> items; // Stores item name and price
    double balance;

public:
    // Constructor to initialize the balance
    ShoppingList() : balance(500.0) {}

    // Function to add an item to the shopping list
    void addItem(const string& itemName, double price) {
        if (price > balance) {
            cout << "Insufficient balance to add this item.\n";
        } else {
            items.push_back(make_pair(itemName, price));
            balance -= price;
            cout << itemName << " added to the shopping list.\n";
        }
    }

    // Function to remove an item from the shopping list
    void removeItem(const string& itemName) {
        bool found = false;
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->first == itemName) {
                balance += it->second;
                items.erase(it);
                cout << itemName << " removed from the shopping list.\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << itemName << " not found in the shopping list.\n";
        }
    }

    // Function to display the shopping list
    void displayList() const {
        if (items.empty()) {
            cout << "Shopping list is empty.\n";
            return;
        }

        cout << "Shopping List:\n";
        for (const auto& item : items) {
            cout << "- " << item.first << ": Rs. " << item.second << "\n";
        }
    }

    // Function to show the current balance
    void showBalance() const {
        cout << "Current balance: Rs. " << balance << "\n";
    }

    // Function to display the total cost of the items in the list
    void totalCost() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.second;
        }
        cout << "Total cost of items: Rs. " << total << "\n";
    }
};

int main() {
    ShoppingList list;
    int choice;
    string itemName;
    double price;

    while (true) {
        cout << "\nShopping List Menu:\n";
        cout << "1. Add item\n";
        cout << "2. Remove item\n";
        cout << "3. Display list\n";
        cout << "4. Show balance\n";
        cout << "5. Show total cost\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter item price: ";
                cin >> price;
                list.addItem(itemName, price);
                break;
            case 2:
                cout << "Enter item name to remove: ";
                cin >> itemName;
                list.removeItem(itemName);
                break;
            case 3:
                list.displayList();
                break;
            case 4:
                list.showBalance();
                break;
            case 5:
                list.totalCost();
                break;
            case 6:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
