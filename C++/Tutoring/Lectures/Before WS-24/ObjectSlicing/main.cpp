#include <iostream>

class Base {
public:
    virtual void display() { std::cout << "Display Base class\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void display() override { std::cout << "Display Derived class\n"; }
    void onlyInDerived() { std::cout << "Function only in Derived\n"; }
};

void functionTakingBase(Base b) {
    b.display();  // This will always call Base's display due to slicing
}

int main() {
    Derived d;
    functionTakingBase(d);  // Object slicing occurs here

    Base* bPtr = &d;
    Base b = *bPtr;  // Slicing, only the Base part of d is copied to b
    b.display();  // Calls Base's display, not Derived's

    Derived* casted = dynamic_cast<Derived*>(bPtr);  // No slicing, proper downcasting
    if (casted) {
        casted->display();  // Proper display method of Derived
    }

    return 0;
}
