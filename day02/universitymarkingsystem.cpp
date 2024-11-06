// write a program in c++ to implement university grading system .
#include <iostream>
#include <iomanip>  // For setting precision
using namespace std;

class SemesterMarkingSystem {
private:
    struct Subject {
        string name;
        double marks;  // Marks obtained
        double credits;  // Credits for the subject
        char grade;  // Grade (A, B, C, etc.)
        double gradePoint;  // Grade points based on the grade
    };

    Subject subjects[5];  // Assuming 5 subjects in a semester

    // Function to calculate grade and grade points based on marks
    char calculateGrade(double marks) {
        if (marks >= 90) return 'A';
        else if (marks >= 80) return 'B';
        else if (marks >= 70) return 'C';
        else if (marks >= 60) return 'D';
        else return 'F';
    }

    // Function to assign grade points based on the grade
    double getGradePoints(char grade) {
        switch (grade) {
            case 'A': return 10.0;
            case 'B': return 8.0;
            case 'C': return 6.0;
            case 'D': return 4.0;
            case 'F': return 0.0;
            default: return 0.0;
        }
    }

public:
    void inputDetails() {
        for (int i = 0; i < 5; i++) {
            cout << "Enter details for Subject " << i + 1 << endl;
            cout << "Name of the subject: ";
            cin >> subjects[i].name;
            cout << "Enter marks obtained (out of 100): ";
            cin >> subjects[i].marks;
            cout << "Enter credits for the subject: ";
            cin >> subjects[i].credits;

            // Calculate grade and grade points
            subjects[i].grade = calculateGrade(subjects[i].marks);
            subjects[i].gradePoint = getGradePoints(subjects[i].grade);

            cout << endl;
        }
    }

    void displayResults() {
       
 }