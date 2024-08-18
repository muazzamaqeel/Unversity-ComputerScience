#include <iostream> 
using namespace std; 

class Test{
public:
    Test() { cout << "Test constructor" << endl; }
   virtual  ~Test() { cout << "Test destructor" << endl; }
};

class Base: public Test 
{ 
public: 
    // Base class constructor 
    Base() { 
        cout << "Base constructor" << endl; 
    } 

    // Base class destructor 
    ~Base() { 
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


    void test(){
    //Base Objb1; 
    cout << "1111111111111111111111111111111" << endl;
    Base* ptr = new Derived(); 
    cout << "1111111111111111111111111111111" << endl;
    Test* B1 = new Derived();
    cout << "1111111111111111111111111111111" << endl;
    cout << "-------------" << endl;
    cout << "-------------" << endl;
    delete ptr;
    cout << "-------------" << endl;
    delete B1;
    cout << "-------------" << endl;
    
    }


int main() { 

    test();
    return 0; 
}
