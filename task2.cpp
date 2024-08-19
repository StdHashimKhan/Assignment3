#include <iostream>
using namespace std;

// Base class
class Shape {
protected:
    string color;

public:
    // Constructor to initialize color
    Shape(string c) : color(c) {
        cout << "Shape constructor called. Color: " << color << endl;
    }

    // Function to set color
    void setColor(string c) {
        color = c;
    }

    // Function to get color
    string getColor() const {
        return color;
    }
};

// Derived class
class Rectangle : public Shape {
private:
    float length;
    float breadth;

public:
    // Constructor chaining to initialize color, length, and breadth
    Rectangle(string c, float l, float b) : Shape(c), length(l), breadth(b) {
        cout << "Rectangle constructor called. Length: " << length << ", Breadth: " << breadth << endl;
    }

    // Function to calculate area
    float calculateArea() const {
        return length * breadth;
    }

    // Function to calculate perimeter
    float calculatePerimeter() const {
        return 2 * (length + breadth);
    }

    // Function to display rectangle details
    void display() const {
        cout << "Rectangle [Color: " << getColor() << ", Length: " << length << ", Breadth: " << breadth << "]" << endl;
        cout << "Area: " << calculateArea() << ", Perimeter: " << calculatePerimeter() << endl;
    }
};

int main() {
    // Creating a Rectangle object
    Rectangle rect("Red", 5.0, 3.0);

    // Display rectangle details
    rect.display();

    return 0;
}
