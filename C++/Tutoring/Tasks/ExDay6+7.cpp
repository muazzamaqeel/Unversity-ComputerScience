/*

Virtual Destructors in C++:

1. What is a virtual destructor in C++ and why is it used?
2. How does a virtual destructor ensure proper cleanup of derived class objects?
3. What happens if a base class destructor is not declared virtual and a derived class object is deleted through a base class pointer?
4. Can you provide a code example where a virtual destructor is necessary to avoid resource leaks?
5. What is the syntax for declaring a virtual destructor in a base class?
6. Explain the concept of polymorphism and how virtual destructors play a role in it.
7. What are the differences between a virtual destructor and a non-virtual destructor in terms of object destruction?
8. How do virtual destructors affect the performance of a program?



Code Fix

#include <iostream>

class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj; // Incorrect behavior due to lack of virtual destructor
    return 0;
}



Overloading Operators in C++:

1. What is operator overloading in C++ and why is it useful?**
2. How do you declare and define an overloaded operator in a C++ class? Provide an example.**
3. Which operators in C++ cannot be overloaded?**
4. How would you overload the `<<` and `>>` operators for input and output streams in C++? Provide a code example.**


		Advanced Questions:
		5. Explain the difference between overloading a binary operator and a unary operator with examples.**
		6. Can you overload operators for user-defined types? Give an example with a custom class.**
		7. What are the rules for overloading the `[]` (subscript) operator in C++?**
		8. What is the difference between member function overloading and friend function overloading for operators?**
		9. How do you overload the assignment operator (`=`) in a C++ class? Provide a code example and explain any considerations to keep in mind.**




Code Fix


#include <iostream>

class Complex {
public:
    Complex(int r, int i) : real(r), imag(i) {}

    // Incorrect syntax for overloading << operator
    friend std::ostream operator<<(std::ostream& os, const Complex& c) {
        os << c.real << " + " << c.imag << "i";
        return os;
    }

private:
    int real, imag;
};

int main() {
    Complex c1(3, 4);
    std::cout << c1 << std::endl; // Error due to incorrect operator overloading
    return 0;
}




Object Slicing in C++:

1. What is object slicing in C++ and when does it occur?**
2. Explain with an example how object slicing can happen when dealing with inheritance.
3. How can object slicing affect the behavior of a program?
4. What are the consequences of object slicing on the polymorphic behavior of objects?
5. How can you prevent object slicing in C++?
6. Why is it important to use virtual functions when dealing with base and derived classes to avoid object slicing?
7. Provide a code example where object slicing occurs and explain the output.



Object Slicing


#include <iostream>

class Base {
public:
    Base() : value(0) {}
    Base(int v) : value(v) {}
    virtual void show() { std::cout << "Base value: " << value << std::endl; }

protected:
    int value;
};

class Derived : public Base {
public:
    Derived(int v) : Base(v), extra(v * 2) {}
    void show() override { std::cout << "Derived value: " << value << ", extra: " << extra << std::endl; }

private:
    int extra;
};

void display(Base b) {
    b.show(); // Object slicing occurs here
}

int main() {
    Derived d(10);
    display(d); // Incorrect behavior due to object slicing
    return 0;
}


















*/
