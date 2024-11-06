// write a program to search Debosmita is in the class or not.
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Function to check if a student is in the vector
bool isStudentPresent(const std::vector<std::string>& students, const std::string& studentName) {
    return std::find(students.begin(), students.end(), studentName) != students.end();
}

int main() {
    // Vector of students present in the class
    std::vector<std::string> students = {"Amit", "Priya", "Rajesh", "Debasmita", "Sanjay", "Neha", "Vikram"};

    std::string searchStudent = "Debasmita";

    std::cout << "Sir has entered the class and is checking for " << searchStudent << "." << std::endl;

    if (isStudentPresent(students, searchStudent)) {
        std::cout << "Good news! " << searchStudent << " is present in the class." << std::endl;
    } else {
        std::cout << "Sorry, " << searchStudent << " is not present in the class." << std::endl;
    }

    return 0;
}