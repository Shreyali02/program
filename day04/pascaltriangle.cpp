// write a program in c++ to implement a reverse pascal triangle.
#include <iostream>
#include <vector>
#include <iomanip>

class ReversedPascalTriangle {
private:
    int rows;
    std::vector<std::vector<unsigned long long>> triangle;

    void generateTriangle() {
        triangle.resize(rows);
        for (int i = 0; i < rows; i++) {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

public:
    ReversedPascalTriangle(int n) : rows(n) {
        generateTriangle();
    }

    void print() {
        int maxWidth = 0;
        for (int i = rows - 1; i >= 0; i--) {
            for (unsigned long long num : triangle[i]) {
                int width = std::to_string(num).length();
                if (width > maxWidth) maxWidth = width;
            }
        }

        for (int i = rows - 1; i >= 0; i--) {
            std::cout << std::string((rows - i - 1) * (maxWidth + 1) / 2, ' ');
            for (unsigned long long num : triangle[i]) {
                std::cout << std::setw(maxWidth) << num << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int n;
    std::cout << "Enter the number of rows for the reversed Pascal's triangle: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Please enter a positive integer." << std::endl;
        return 1;
    }

    ReversedPascalTriangle triangle(n);
    triangle.print();

    return 0;
}