#include <iostream>
#include "string"
using namespace std;

///////////////////////////////////////////
//Color is an abstract class (interface) with a pure virtual method fill().
//It represents the Implementor in the Bridge pattern.
// Implementor interface
class Color {
public:
    virtual ~Color() = default;
    virtual string fill() const = 0;
};
///////////////////////////////////////////


///////////////////////////////////////////
//Shape is an abstract class with a protected member color of type const Color&.
//The Shape class has a constructor that initializes the color member.
//It represents the Abstraction in the Bridge pattern.
// Abstraction
class Shape {
protected:
    const Color& color;
public:
    Shape(const Color& c) : color(c) {}
    virtual ~Shape() = default;
    virtual string draw() const = 0;
};
///////////////////////////////////////////




///////////////////////////////////////////
//Circle is a concrete class that inherits from Shape.
//It overrides the draw() method to provide a specific implementation.
//It represents the RefinedAbstraction in the Bridge pattern.
// RefinedAbstraction
class Circle : public Shape {
public:
    Circle(const Color& c) : Shape(c) {}
    string draw() const override {
        return "Circle filled with " + color.fill();
    }
};
///////////////////////////////////////////






///////////////////////////////////////////
//Red and Blue are concrete classes that implement the Color interface.
//These classes provide specific implementations of the fill() method.
//They represent the ConcreteImplementor in the Bridge pattern.
// Concrete Class
class Red : public Color {
public:
    string fill() const override {
        return "Red";
    }
};
// Concrete Class
class Blue : public Color {
public:
    string fill() const override {
        return "Blue";
    }
};
///////////////////////////////////////////
int main() {
    Red red;
    Blue blue;

    Circle redCircle(red);
    Circle blueCircle(blue);

    cout << redCircle.draw() << endl; // Output: Circle filled with Red
    cout << blueCircle.draw() << endl; // Output: Circle filled with Blue


    redCircle.

    return 0;
}
