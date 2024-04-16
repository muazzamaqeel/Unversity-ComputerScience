#include <iostream>

// Template function to return the maximum of two values
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template class to represent a box that can hold any type of item
template<typename T>
class Box {
public:
    // Constructor
    Box(T initialValue) : value(initialValue) {}

    // Function to set value in the box
    void setValue(T newValue) {
        value = newValue;
    }

    // Function to get value from the box
    T getValue() const {
        return value;
    }

private:
    T value;
};

int main() {
    // Using the template function with integer values
    int intA = 5, intB = 10;
    std::cout << "Max of " << intA << " and " << intB << " is " << getMax(intA, intB) << std::endl;

    // Using the template function with double values
    double doubleA = 3.14, doubleB = 1.59;
    std::cout << "Max of " << doubleA << " and " << doubleB << " is " << getMax(doubleA, doubleB) << std::endl;

    // Creating a box to store an integer
    Box<int> intBox(123);
    std::cout << "The box contains: " << intBox.getValue() << std::endl;

    // Creating a box to store a string
    Box<std::string> stringBox("Hello, World!");
    std::cout << "The box contains: " << stringBox.getValue() << std::endl;

    return 0;
}
