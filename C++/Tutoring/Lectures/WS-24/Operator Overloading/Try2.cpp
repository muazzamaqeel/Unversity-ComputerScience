#include <iostream>

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v = 0) : value(v) {}

    // Overloading the + operator
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    // Display method
    void display() const {
        std::cout << value << std::endl;
    }
};

int main() {
    Number n1(5);
    Number n2(10);

    Number n3 = n1 + n2;  // Using overloaded + operator

    std::cout << "Number 1: ";
    n1.display();

    std::cout << "Number 2: ";
    n2.display();

    std::cout << "Sum (n1 + n2): ";
    n3.display();

    return 0;
}
