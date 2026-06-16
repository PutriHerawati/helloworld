#include <iostream>
using namespace std;

// Abstract Class (Base Class)
class Shape {
public:
    // Pure Virtual Function (This makes the class abstract)
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
};

// Derived Class 1
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    
    void draw() override {
        cout << "Drawing a Circle..." << endl;
    }
    
    double calculateArea() override {
        return 3.14159 * radius * radius;
    }
};

// Derived Class 2
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    
    void draw() override {
        cout << "Drawing a Rectangle..." << endl;
    }
    
    double calculateArea() override {
        return length * width;
    }
};

int main() {
    cout << "=== OOP ABSTRACT CLASS DEMO ===" << endl;
    cout << "--------------------------------" << endl;

    // Creating objects using Base Class pointers (Polymorphism)
    Shape* shape1 = new Circle(7.0);
    Shape* shape2 = new Rectangle(5.0, 4.0);

    // Executing methods
    shape1->draw();
    cout << "Circle Area: " << shape1->calculateArea() << " sq units\n" << endl;

    shape2->draw();
    cout << "Rectangle Area: " << shape2->calculateArea() << " sq units\n" << endl;

    cout << "--------------------------------" << endl;
    cout << "Program executed successfully!" << endl;

    // Cleaning up memory
    delete shape1;
    delete shape2;

    return 0;
}
