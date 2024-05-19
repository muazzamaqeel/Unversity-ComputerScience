
/*

Composition, Aggregation, and Association in C++
Below are five questions where you need to determine whether the relationship in the provided C++ code is composition, aggregation, or association.


1. Look at the following code and identify the type of relationship:

    class Engine {
    public:
        void start() {
            // Engine start logic
        }
    };

    class Car {
    private:
        Engine engine;  // Car contains an Engine
    public:
        void startCar() {
            engine.start();
        }
    };
    
Answer: 

2. Look at the following code and identify the type of relationship:

    class Engine {
    public:
        void start() {
            // Engine start logic
        }
    };

    class Car {
    private:
        Engine* engine;  // Car aggregates an Engine
    public:
        Car(Engine* eng) : engine(eng) {}
        void startCar() {
            engine->start();
        }
    };
    
Answer: 

3. Look at the following code and identify the type of relationship:

    class Professor {
    public:
        void teach() {
            // Teaching logic
        }
    };

    class Course {
    private:
        Professor* professor;  // Course uses a Professor
    public:
        Course(Professor* prof) : professor(prof) {}
        void conductClass() {
            professor->teach();
        }
    };
    
Answer: 

4. Look at the following code and identify the type of relationship:

    class Department {
    public:
        void operate() {
            // Department operation logic
        }
    };

    class Company {
    private:
        Department* department;  // Company aggregates a Department
    public:
        Company(Department* dept) : department(dept) {}
        void manage() {
            department->operate();
        }
    };
    
Answer: 

5. Look at the following code and identify the type of relationship:

    class Battery {
    public:
        void charge() {
            // Charging logic
        }
    };

    class Laptop {
    private:
        Battery battery;  // Laptop contains a Battery
    public:
        void chargeBattery() {
            battery.charge();
        }
    };
    
Answer: 

*/




// Revision of C++ Concepts: Pointers, OOP, Classes, Inheritance, and Polymorphism


1. Pointers: What is a pointer in C++? Write a code snippet to demonstrate how to declare, initialize, and use a pointer.

    #include <iostream>
    using namespace std;

    int main() {
        int var = 42;      // Declare an integer variable
        int* ptr = &var;   // Declare a pointer and initialize with the address of var

        cout << "Value of var: " << var << endl;       // Output the value of var
        cout << "Pointer ptr points to address: " << ptr << endl; // Output the address stored in ptr
        cout << "Value pointed to by ptr: " << *ptr << endl; // Output the value pointed to by ptr

        return 0;
    }
    
Answer: A pointer is a variable that stores the memory address of another variable.

2. Object Oriented Programming: What are the four pillars of Object Oriented Programming? Provide a brief explanation and code to demonstrate encapsulation.

    class Encapsulated {
    private:
        int hiddenData;  // Private data member

    public:
        void setData(int data) {  // Public method to set the value of hiddenData
            hiddenData = data;
        }

        int getData() {  // Public method to get the value of hiddenData
            return hiddenData;
        }
    };

    int main() {
        Encapsulated obj;
        obj.setData(100);  // Set the value of hiddenData
        cout << "Value: " << obj.getData() << endl;  // Get the value of hiddenData

        return 0;
    }
    
Answer: The four pillars of OOP are Encapsulation, Abstraction, Inheritance, and Polymorphism. Encapsulation is demonstrated in the code above.

3. Classes: How do you define a class in C++? Write a code snippet to demonstrate a simple class with a constructor and a member function.

    class SimpleClass {
    private:
        int data;

    public:
        SimpleClass(int val) {  // Constructor
            data = val;
        }

        void display() {  // Member function
            cout << "Data: " << data << endl;
        }
    };

    int main() {
        SimpleClass obj(10);  // Create an object of SimpleClass
        obj.display();  // Call the member function

        return 0;
    }
    
Answer: A class in C++ is defined using the 'class' keyword. The code above demonstrates a simple class with a constructor and a member function.

4. Inheritance: What is inheritance in C++? Write a code snippet to demonstrate single inheritance.

    class Base {
    public:
        void display() {
            cout << "Base class display function" << endl;
        }
    };

    class Derived : public Base {  // Derived class inheriting from Base class
    public:
        void show() {
            cout << "Derived class show function" << endl;
        }
    };

    int main() {
        Derived obj;  // Create an object of Derived class
        obj.display();  // Call base class function
        obj.show();     // Call derived class function

        return 0;
    }
    
Answer: Inheritance is a feature of OOP that allows a class to inherit properties and behavior from another class. The code above demonstrates single inheritance.

5. Polymorphism: What is polymorphism in C++? Write a code snippet to demonstrate runtime polymorphism using virtual functions.

    class Base {
    public:
        virtual void display() {  // Virtual function
            cout << "Base class display function" << endl;
        }
    };

    class Derived : public Base {
    public:
        void display() override {  // Override base class function
            cout << "Derived class display function" << endl;
        }
    };

    int main() {
        Base* basePtr;  // Base class pointer
        Derived derivedObj;  // Derived class object
        basePtr = &derivedObj;

        basePtr->display();  // Runtime polymorphism

        return 0;
    }
    
Answer: Polymorphism is the ability of a function or an object to take on many forms. The code above demonstrates runtime polymorphism using virtual functions.



