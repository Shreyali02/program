// write a program in c++  to calculate the simple interest withe the default of 15 percent.
#include <iostream>
#include <iomanip>

// Function to calculate simple interest
double calculateSimpleInterest(double principal, int time, double rate = 15.0) {
    return (principal * time * rate) / 100.0;
}

int main() {
    double principal;
    int time;
    double rate;
    char useDefaultRate;

    // Input principal amount
    std::cout << "Enter the principal amount: ";
    std::cin >> principal;

    // Input time period in years
    std::cout << "Enter the time period (in years): ";
    std::cin >> time;

    // Ask if user wants to use default rate
    std::cout << "Do you want to use the default interest rate of 15%? (y/n): ";
    std::cin >> useDefaultRate;

    double interest;

    if (useDefaultRate == 'y' || useDefaultRate == 'Y') {
        // Use default rate
        interest = calculateSimpleInterest(principal, time);
        std::cout << "Calculating interest with default rate of 15%\n";
    } else {
        // Input custom rate
        std::cout << "Enter the interest rate (in percentage): ";
        std::cin >> rate;
        interest = calculateSimpleInterest(principal, time, rate);
    }

    // Calculate total amount
    double totalAmount = principal + interest;

    // Display results
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nSimple Interest Calculation:\n";
    std::cout << "Principal Amount: $" << principal << std::endl;
    std::cout << "Time Period: " << time << " years" << std::endl;
    std::cout << "Interest Rate: " << (useDefaultRate == 'y' || useDefaultRate == 'Y' ? 15.0 : rate) << "%" << std::endl;
    std::cout << "Interest Amount: $" << interest << std::endl;
    std::cout << "Total Amount: $" << totalAmount << std::endl;

    return 0;
}