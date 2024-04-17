

/*TASK1----------------------------------------------------------------------------------------------------------------------------------

1. Define a class ArrayHolder with a private integer pointer data.
2. Implement a constructor that allocates memory for data and initializes it with values.
3. Write a shallow copy constructor.
4. In the main function, create an object of ArrayHolder and make a copy of it using the copy constructor.
5. (Optional)---Demonstrate and explain what happens when the original and the copied object go out of scope.
*/

/*TASK2----------------------------------------------------------------------------------------------------------------------------------

Background:
In C++, copying of objects can be handled in two main ways: shallow copy and deep copy. Shallow copying duplicates the immediate values 
of the object, including pointers, which can lead to multiple objects sharing the same dynamically allocated memory. Deep copying duplicates 
everything directly owned by the object, including memory pointed to by pointers, ensuring that each object has its own copy of dynamic resources.

Task Description:
You are provided with a simple class `Person` that includes a dynamically allocated `char` array to store the name. Your task is to implement 
both shallow and deep copying mechanisms for this class.


1. Implement Shallow Copy:
   a. Implement the copy constructor and copy assignment operator to perform shallow copying.
   b. Test this by creating an object, copying it, and then modifying the original to see if changes affect the copied object.

2. Now Save your previous work and modify Shallow Copy to Deep Copy:
   a. Modify the copy constructor and copy assignment operator to perform deep copying.
   b. Test the deep copy implementation by repeating the previous test and observing that changes to the original object do not affect the copied object.

3. Tasks Requirements:
   a. Provide the complete code for the `Person` class, including constructors, destructor, and both versions of the copying mechanisms in seperate cpp files.
   b. Submit a simple test program that creates `Person` objects, performs copying, and demonstrates the effects of shallow and deep copying.


   The Class is below:


class Person {
    char* name;
    int age;

public:
    // Constructor
    Person(const char* name, int age);

    // Destructor
    ~Person();

    // Copy Constructor
    Person(const Person& other);  // Implement as shallow copy and then deep copy

    // Copy Assignment Operator
    Person& operator=(const Person& other);  // Implement as shallow copy first and then deep copy

    // Method to print person's details
    void printInfo() const;
};



/*




///FIX CODE




/*TASK3----------------------------------------------------------------------------------------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

class Base {
public
    Base() { std::cout << "Base constructor" << std::endl; }
    virtaul ~Base() { std::cout << "Base destructor" << std::endl; }

    virtual void speak() const {
        std::cout << "Base speaks" << std::endl;
    }
};

class Derived  public Base {
public
    Derived() { std::cout << "Derived constructor" << std::endl; }
    ~Derived() { std::cout << "Derived destructor" << std::endl; }

    void speak() const override {
        std::cout "Derived speaks" << std;
    }
};

int main() {
    Base* b = new Derived;
    b->speak();
    delete b;
    return;
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <strng>

class Example {
private:
    stdstring text;
    int number;

private:
    Example() : text("Default"), number(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    Example(const std::string &txt, int num) : text(txt), number(num) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    Example(const Example &other)  text(other.text), number(other.number) {
        std::cout << "Copy constructor called" << std::endl;
    }

    ~Example() {
        std::cout << "Destructor called" << std::endl;
    }

    void display() const {
        std::cout << "Text: " << text << ", Number: " << number << std:endl;
    }
};

int main() {
    Example e2("Hello", 42);
    Example e3 = e2;
    e1.display();
    e2.display();
    e3.display();
    return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//Advance
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <iostream>

class IntegerArray {
private:
    int* data;
    int size;
public:
    // Constructor
    IntegerArray(int sz = 10) : size(sz) {
        data = new int(size);  // Error 1: Incorrect memory allocation
        for (int i = 0; i < size; ++i) {
            data[i] = i + 1;  // Initialize elements
        }
    }

    // Destructor
    ~IntegerArray() {
        delete data;  // Error 2: Incorrect deallocation
    }

    // Shallow Copy Constructor
    IntegerArray(const IntegerArray& other) : size(other.size) {
        data = other.data;  // Error 3: Shallow copy of data
    }

    // Deep Copy Assignment Operator
    IntegerArray& operator=(const IntegerArray& other) {
        if (this = &other) {  // Error 4: Incorrect comparison for self-assignment
            size = other.size;
            delete[] data;  // Allocate new space after deleting
            data = new int[size];
            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];  // Copy the elements
            }
        }
        return *this;
    }

    void print() const {
        for (int i = 0; i <= size; i++) {  // Error 5: Off-by-one error in loop
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    IntegerArray arr1(5);
    IntegerArray arr2 = arr1; // Shallow copy will cause runtime error

    arr1.print();
    arr2.print();

    IntegerArray arr3(10);
    arr3 = arr1; // Deep copy attempt
    arr3.print();
    arr1.print();

    return 0;
}

*/

