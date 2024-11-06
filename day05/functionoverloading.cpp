// write a program in c++ to implement function overloading and and finding the area of triangle ,rectangle and circle.
#include <iostream>
#include <cmath>  // For using M_PI constant for circle calculations

class Shape {
public:
    // Function to calculate the area of a triangle
    double area(double base, double height) {
        return 0.5 * base * height;
    }

    // Function to calculate the area of a circle
    double area(double radius) {
        return M_PI * radius * radius;
    }

    // Function to calculate the area of a rectangle
    double area(double length, double width) {
        return length * width;
    }
};

int main() {
    Shape shape;
    
    // Triangle: base = 5, height = 10
    double triangleArea = shape.area(5, 10);
    std::cout << "Area of the triangle: " << triangleArea << std::endl;
    
    // Circle: radius = 7
    double circleArea = shape.area(7);
    std::cout << "Area of the circle: " << circleArea << std::endl;
    
    // Rectangle: length = 8, width = 4
    double rectangleArea = shape.area(8, 4);
    std::cout << "Area of the rectangle: " << rectangleArea << std::endl;

    return 0;
}
