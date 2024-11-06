// write a program in c++ to calculate the prize of the item and display the total
#include <iostream>
using namespace std;

int main() {
    int n;

    // Get the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    // Arrays to store items and their prices
    string items[n];
    float prices[n];

    // Input item names and their prices
    for (int i = 0; i < n; i++) {
        cout << "Enter item " << i + 1 << " name: ";
        cin >> items[i];  // Reading the item name

        cout << "Enter price of " << items[i] << ": ";
        cin >> prices[i];  // Reading the item price
    }

    // Print items and their corresponding prices
    cout << "\nItems and their Prices:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item: " << items[i] << " | Price: $" << prices[i] << endl;
    }

    return 0;
}
