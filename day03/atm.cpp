// write a program in c++ to implement a atm interface .

#include <iostream>
#include <string>
#include <limits>

class ATM {
private:
    double balance;
    int pin;

public:
    ATM() : balance(0), pin(1234) {}

    bool verifyPin(int enteredPin) {
        return enteredPin == pin;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrawal successful. Remaining balance: " << balance << "\n";
        }
    }

    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << "\n";
    }

    void transfer(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            std::cout << "Transfer successful. Remaining balance: " << balance << "\n";
        }
    }

    void showBalance() {
        std::cout << "Your current balance is: " << balance << "\n";
    }
};

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getMenuChoice() {
    int choice;
    while (true) {
        std::cout << "\nATM Menu:\n"
                  << "1. Withdraw\n"
                  << "2. Deposit\n"
                  << "3. Transfer\n"
                  << "4. Check Balance\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        if (std::cin >> choice) {
            clearInputBuffer();
            return choice;
        } else {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
        }
    }
}

double getAmount(const std::string& action) {
    double amount;
    while (true) {
        std::cout << "Enter amount to " << action << ": ";
        if (std::cin >> amount) {
            clearInputBuffer();
            return amount;
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
            clearInputBuffer();
        }
    }
}

int getPIN() {
    int enteredPin;
    while (true) {
        std::cout << "Enter your 4-digit PIN: ";
        if (std::cin >> enteredPin) {
            clearInputBuffer();
            return enteredPin;
        } else {
            std::cout << "Invalid input. Please enter a valid PIN.\n";
            clearInputBuffer();
        }
    }
}

int main() {
    ATM atm;
    const int maxAttempts = 3;

    while (true) {
        int choice = getMenuChoice();

        if (choice == 5) {
            std::cout << "Thank you for using our ATM. Goodbye!\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice. Please try again.\n";
            continue;
        }

        bool pinVerified = false;
        int attempts = 0;

        while (attempts < maxAttempts && !pinVerified) {
            int enteredPin = getPIN();
            if (atm.verifyPin(enteredPin)) {
                pinVerified = true;
            } else {
                attempts++;
                std::cout << "Incorrect PIN. " << (maxAttempts - attempts) << " attempts remaining.\n";
            }
        }

        if (!pinVerified) {
            std::cout << "Too many incorrect PIN attempts. Your card has been blocked. Please contact your bank.\n";
            break;
        }

        switch (choice) {
            case 1:
                atm.withdraw(getAmount("withdraw"));
                break;
            case 2:
                atm.deposit(getAmount("deposit"));
                break;
            case 3:
                atm.transfer(getAmount("transfer"));
                break;
            case 4:
                atm.showBalance();
                break;
        }
    }

    return 0;
}