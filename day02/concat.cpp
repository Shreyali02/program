// write a program in c++ to concat and copy string.
#include <iostream>
using namespace std;

// Function to copy one string to another
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Null-terminate the destination string
}

// Function to concatenate two strings
void concatenateStrings(char dest[], const char src[]) {
    int i = 0, j = 0;

    // Find the end of the destination string
    while (dest[i] != '\0') {
        i++;
    }

    // Append source string to the destination string
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';  // Null-terminate the destination string
}

// Function to compare two strings
int compareStrings(const char str1[], const char str2[]) {
    int i = 0;
    
    // Compare character by character
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];  // Return the ASCII difference
        }
        i++;
    }

    // If one string is longer than the other
    return str1[i] - str2[i];
}

int main() {
    char str1[100], str2[100], copy[100], concatenated[200];

    // Input strings from the user
    cout << "Enter the first string: ";
    cin.getline(str1, 100);
    cout << "Enter the second string: ";
    cin.getline(str2, 100);

    // Copy str1 to another string
    copyString(copy, str1);
    cout << "Copied string: " << copy << endl;

    // Concatenate str1 and str2
    copyString(concatenated, str1);  // Start with str1 in concatenated
    concatenateStrings(concatenated, str2);
    cout << "Concatenated string: " << concatenated << endl;

    // Compare the two strings
    int comparisonResult = compareStrings(str1, str2);
    if (comparisonResult == 0) {
        cout << "The strings are equal." << endl;
    } else if (comparisonResult < 0) {
        cout << "The first string is lexicographically smaller than the second string." << endl;
    } else {
        cout << "The first string is lexicographically greater than the second string." << endl;
    }

    return 0;
}
