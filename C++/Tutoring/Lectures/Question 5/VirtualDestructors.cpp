#include <iostream> 
using namespace std; 

// Base class 
class Base { 
public: 
    // Base class constructor 
    Base() { 
        cout << "Base constructor" << endl; 
    } 

    // Base class destructor 
    virtual ~Base() { 
        cout << "Base destructor" << endl; 
    } 
}; 

// Derived class which inherits from Base class 
class Derived : public Base { 
public: 
    int* ptr; 

    // Derived class constructor 
    Derived() { 
        ptr = new int[10]; // Allocate memory for an array of 10 integers
        cout << "Derived constructor" << endl; 
    } 

    // Derived class destructor 
    ~Derived() { 
        delete[] ptr; // Correct way to free the allocated memory
        cout << "Derived destructor" << endl; 
    } 
}; 

int main() { 
    // Create a new Derived object and assign its address to a Base class pointer
    Base* ptr = new Derived(); 
    delete ptr;

    cout << "----------------" << endl;
    Base *ptr2 = new Base();

    // Deleting the object through the Base class pointer
    // Because the Base class destructor is not virtual, it will not call the Derived class destructor.
    // This can lead to resource leak if the Derived class was holding any resources.

    return 0; 
}
