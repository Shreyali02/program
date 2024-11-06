// write a program in c++ to access an element using pointer.
#include <iostream>
using namespace std;

int main() {
    // Declare an array of integers
    int arr[5] = {10, 20, 30, 40, 50};
    
    // Declare a pointer that points to the first element of the array
    int *ptr = arr;  // or int *ptr = &arr[0];

    // Access the elements of the array using the pointer
    cout << "Array elements accessed using pointers:" << endl;

    for (int i = 0; i < 5; i++) {
        // Print the current element using pointer dereferencing
        cout << "Element " << i + 1 << ": " << *(ptr + i) << endl;
    }

    return 0;
}
