// write a progam in c++ t0 mesure the distance in feet and inches.
#include <iostream>

class Distance {
private:
    int feet;
    int inches;

public:
    // Constructor to initialize the distance
    Distance(int f = 0, int i = 0) {
        feet = f;
        inches = i;
    }

    // Function to add two Distance objects
    Distance add(const Distance& d) {
        Distance result;
        result.inches = inches + d.inches;
        result.feet = feet + d.feet;

        // Convert every 12 inches to 1 foot
        if (result.inches >= 12) {
            result.feet += result.inches / 12;
            result.inches %= 12;
        }

        return result;
    }

    // Function to display the distance
    void display() const {
        std::cout << feet << " feet, " << inches << " inches" << std::endl;
    }
};

int main() {
    // Create two Distance objects
    Distance d1(5, 9);  // 5 feet 9 inches
    Distance d2(3, 11); // 3 feet 11 inches

    // Add the distances
    Distance d3 = d1.add(d2);

    // Display the result
    std::cout << "Distance 1: "; d1.display();
    std::cout << "Distance 2: "; d2.display();
    std::cout << "Sum of distances: "; d3.display();

    return 0;
}
