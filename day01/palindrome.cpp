// check if string is a palindrome or not without using any libraries.
#include <iostream>

// Function to calculate the length of a string
int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to check if a string is a palindrome
bool isPalindrome(const char* str) {
    int len = stringLength(str);
    const char* start = str;
    const char* end = str + len - 1;

    while (start < end) {
        // Skip non-alphanumeric characters from the start
        while (start < end && !isalnum(*start)) start++;
        // Skip non-alphanumeric characters from the end
        while (start < end && !isalnum(*end)) end--;

        // Compare characters, ignoring case
        if (tolower(*start) != tolower(*end)) {
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    std::cout << "Enter a string to check if it's a palindrome: ";
    std::cin.getline(input, MAX_LENGTH);

    if (isPalindrome(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}