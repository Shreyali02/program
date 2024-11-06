// write a program in c++  to calculate the average of students using friend function.
#include <iostream>
#include <string>
#include <vector>

class SectionB; // Forward declaration

class SectionA {
private:
    std::vector<double> marks;
    std::string sectionName;

public:
    SectionA() : sectionName("A") {}

    void addMarks(double mark) {
        marks.push_back(mark);
    }

    friend double calculateAverage(const SectionA& secA, const SectionB& secB);
};

class SectionB {
private:
    std::vector<double> marks;
    std::string sectionName;

public:
    SectionB() : sectionName("B") {}

    void addMarks(double mark) {
        marks.push_back(mark);
    }

    friend double calculateAverage(const SectionA& secA, const SectionB& secB);
};

// Friend function to calculate average
double calculateAverage(const SectionA& secA, const SectionB& secB) {
    double totalMarks = 0;
    int totalStudents = secA.marks.size() + secB.marks.size();

    for (double mark : secA.marks) {
        totalMarks += mark;
    }

    for (double mark : secB.marks) {
        totalMarks += mark;
    }

    return totalMarks / totalStudents;
}

int main() {
    SectionA sectionA;
    SectionB sectionB;

    std::cout << "Enter marks for 5 students in Section A:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        double mark;
        std::cout << "Student " << i + 1 << ": ";
        std::cin >> mark;
        sectionA.addMarks(mark);
    }

    std::cout << "\nEnter marks for 5 students in Section B:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        double mark;
        std::cout << "Student " << i + 1 << ": ";
        std::cin >> mark;
        sectionB.addMarks(mark);
    }

    double average = calculateAverage(sectionA, sectionB);

    std::cout << "\nThe average marks of all 10 students is: " << average << std::endl;

    return 0;
}