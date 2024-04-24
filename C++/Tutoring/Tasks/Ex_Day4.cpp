//Intro: Day 4 of C++ tutoring - Tasks
//Some helpful Videos link:

//https://www.youtube.com/watch?v=5FmszF_Tb2A
//https://www.youtube.com/watch?v=KVgtlDvOiLc



/*
1.
Overload the + operator for a Point class.
Provide a class definition for Point that includes x and y coordinates as private members. 
Write a member function to overload the + operator to add two Point objects, returning a new Point object that represents the sum of the coordinates
*/


/*
2. Write a code snippet to demonstrate the use of static_cast for converting a float to an int.
*/


/*
3.
Describe a scenario where static_cast would fail where dynamic_cast would succeed.
*/



/*
4.
Given a class hierarchy with a base class Animal and derived classes Dog and Cat, demonstrate how to use dynamic_cast to safely convert an Animal pointer to a Dog pointer.
*/



/*****FIX-CODE******/


///////////Question 1: Operator Overloading

class Complex {
public:
    double real, imag;
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this; // Issue here
    }
};


///////////Question 2: Static Casting

void printInt(double value) {
    int intVal = static_cast<int>(value);
    std::cout << "The integer value is: " << intVal << std::endl;
}

int main() {
    printInt(3.14159); // Issue here, improper use of function.
}


///////////Question 3: Dynamic Casting
class Base {
public:
    virtual ~Base() {}
};
class Derived : public Base {
public:
    void showDerived() { std::cout << "In Derived\n"; }
};

int main() {
    Base *b = new Derived();
    Derived *d = dynamic_cast<Derived*>(b);
    d->showDerived(); // Issue here, need to check if d is not null.
}


///////////Question 4: Rule of Three
class StringWrapper {
    char* data;
public:
    StringWrapper(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Destructor is missing.
    // Copy constructor is missing.
    // Copy assignment operator is missing.
};


//////////Question 5: Combination of Overloading and Casting
class Currency {
public:
    int dollars, cents;
    Currency(int d, int c) : dollars(d), cents(c) {}

    operator int() const {
        return static_cast<int>(dollars) + cents / 100; // Issue here
    }

    Currency& operator++() {
        ++dollars; // Logical issue here
        return *this;
    }
};
