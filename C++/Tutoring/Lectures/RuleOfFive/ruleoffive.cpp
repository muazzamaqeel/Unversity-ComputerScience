

// Rule of Three
//The Rule of Three in C++ states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, 
//it likely needs all three. This is because these functions manage the class's resources and ensure proper resource handling and memory management.

#include <iostream>

class Example {
private:
    int* data;

public:
    // Constructor
    Example(int value) {
        data = new int(value);
    }

    // Destructor
    ~Example() {
        delete data;
    }

    // Copy constructor
    Example(const Example& other) {
        data = new int(*other.data);
    }

    // Copy assignment operator
    Example& operator=(const Example& other) {
        if (this != &other) {  // Check for self-assignment
            delete data;       // Free existing resource
            data = new int(*other.data);
        }
        return *this;
    }

    void display() {
        std::cout << "Value: " << *data << std::endl;
    }
};

int main() {
    Example obj1(10);
    Example obj2 = obj1;  // Calls copy constructor
    Example obj3(20);
    obj3 = obj1;          // Calls copy assignment operator

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}





// Rule of Five
//The Rule of Five in C++ extends the Rule of Three to include the move constructor and move assignment operator.

#include <iostream>

class Example {
private:
    int* data;

public:
    // Constructor
    Example(int value) {
        data = new int(value);
    }

    // Destructor
    ~Example() {
        delete data;
    }

    // Copy constructor
    Example(const Example& other) {
        data = new int(*other.data);
    }

    // Copy assignment operator
    Example& operator=(const Example& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move constructor
    Example(Example&& other) noexcept : data(other.data) {
        other.data = nullptr;  // Leave the moved-from object in a valid state
    }

    // Move assignment operator
    Example& operator=(Example&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    void display() {
        if (data)
            std::cout << "Value: " << *data << std::endl;
        else
            std::cout << "Value: null" << std::endl;
    }
};

int main() {
    Example obj1(10);
    Example obj2 = std::move(obj1);  // Calls move constructor
    Example obj3(20);
    obj3 = std::move(obj2);          // Calls move assignment operator

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}



// The copy constructor and copy assignment operator handle copying resources.
// The move constructor and move assignment operator handle transferring resources 
// without copying, leaving the moved-from object in a valid but unspecified state (often set to nullptr).

// Move Constructor: Transfers ownership of resources from one object to another, 
// leaving the source object in a valid but unspecified state.
// Copy Constructor: Creates a copy of an object, duplicating its resources.

