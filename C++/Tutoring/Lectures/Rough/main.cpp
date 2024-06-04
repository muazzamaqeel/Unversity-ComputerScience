#include <iostream>

class Example {
private:
    int* data;

public:
    // Constructor
    Example(int value) {
        data = new int(value);
        std::cout << "Constructor called\n";
    }

    // Destructor
    ~Example() {
        delete data;
        std::cout << "Destructor called\n";
    }

    // Copy constructor
    Example(const Example& other) {
        data = new int(*other.data);
        std::cout << "Copy constructor called\n";
    }

    // Copy assignment operator
    Example& operator=(const Example& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        std::cout << "Copy assignment operator called\n";
        return *this;
    }

    // Move constructor
    Example(Example&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor called\n";
    }

    // Move assignment operator
    Example& operator=(Example&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        std::cout << "Move assignment operator called\n";
        return *this;
    }

    void display() const {
        if (data)
            std::cout << "Value: " << *data << std::endl;
        else
            std::cout << "Value: null" << std::endl;
    }
};

int main() {
    Example obj1(10);         // Constructor
    Example obj2 = std::move(obj1);  // Move constructor
    Example obj3(20);         // Constructor
    obj3 = std::move(obj2);   // Move assignment operator

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}
