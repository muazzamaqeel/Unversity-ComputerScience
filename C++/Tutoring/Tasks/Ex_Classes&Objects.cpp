/// C++ Exercises

// Classes and Objects
// 1. Define a basic C++ class named `Car` with two public members: `brand` and `year`.
//    Demonstrate creating an instance of `Car` in the main function and accessing its members.

// 2. Write a C++ program that creates a class named `Person`. The class should have
//    two public attributes: `name` and `age`. In the main function, create an object
//    of the `Person` class and assign values to its attributes, then print these
//    values to the console.

// Constructors
// 3. Create a class called `Rectangle` in C++ that has two private attributes:
//    `length` and `width`. Write a constructor for the class that allows those two
//    attributes to be initialized when an object is created. Show how to create an
//    instance of `Rectangle` with specific dimensions.

// 4. Demonstrate the use of a default constructor in C++ by creating a class named `Box`
//    with default dimensions if no parameters are passed, but allows for `length`,
//    `breadth`, and `height` to be set at the time of object creation.

// Destructors
// 5. Explain the purpose of a destructor in a C++ class by writing a simple class named
//    `Message` that prints "Object is being created" in its constructor and "Object is
//    being destroyed" in its destructor. Create an instance of this class in the main
//    function to see the destructor in action.

// Inheritance
// 6. Implement a simple inheritance example in C++ by creating a base class named `Animal`
//    with a function `speak()` that outputs "Animal makes a sound." Then, derive a class
//    named `Dog` from `Animal` that overrides the `speak()` function to output "Dog barks."

// Polymorphism
// 7. Show how polymorphism works in C++ with a function that takes a reference to a base
//    class `Shape` and calls a virtual function `draw()`. Define two derived classes,
//    `Circle` and `Square`, each implementing its own version of `draw()`. Demonstrate
//    calling `draw()` on objects of these classes through a pointer to `Shape`.

// Advance Questions
// 8. Using classes, constructors, and inheritance, create a basic C++ program where a class
//    `Vehicle` is the base class with attributes like `brand` and `year`. Derive two classes
//    from it: `Car` and `Bike`, each adding specific attributes like `carType` and `bikeType`.
//    Demonstrate creating instances of these derived classes and accessing their properties
//    in the main function.

// 9. Write a C++ program that includes a class with a constructor, a destructor, and
//    demonstrates basic inheritance and polymorphism. Use a class `Book` with attributes
//    for title and author, a derived class `Ebook` that adds a file size attribute, and
//    polymorphic methods to display book details.





// The following C++ code is intended to define a class `Rectangle` with a constructor
// that initializes its length and width. Identify and correct the errors in the code.
/*
class Rectangle {
public:
    int length;
    int width;

    Rectangle(int l, int w) {
        length = l;
        width = w;
    }
}

int main() {
    Rectangle rect(10, 20);
    cout << "Rectangle dimensions: " << rect.length << " x " << rect.width << endl;
    return 0;
}
*/


// This C++ code attempts to model a `Car` class with private attributes that are
// accessible via public methods. Find and fix the mistake in the code.
/*
class Car {
private:
    string brand = "Ford";
    int year = 2020;

public:
    string getBrand() {
        return brand;
    }

    int getYear() {
        return year;
    }
};

int main() {
    Car myCar;
    cout << myCar.brand << " " << myCar.year << endl;
    return 0;
}
*/


// The following C++ program is supposed to create a base class `Animal` and a derived
// class `Dog` that inherits from `Animal`. Identify and rectify the errors in the inheritance.
/*
class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog inherits Animal {
public:
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.speak();
    return 0;
}
*/


// This code is meant to demonstrate polymorphism with a virtual function in a base
// class `Shape` and an overridden function in a derived class `Circle`. Correct the mistakes.
/*
class Shape {
public:
    void draw() {
        cout << "Drawing Shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Shape *shape = new Circle();
    shape->draw();
    delete shape;
    return 0;
}
*/


// In this C++ code, a class `Message` is supposed to define a constructor and a destructor
// that print messages to the console. Find and fix the errors related to the destructor.
/*
class Message {
public:
    Message() {
        cout << "Message created" << endl;
    }

    ~Message {
        cout << "Message destroyed" << endl;
    }
};

int main() {
    Message msg;
    return 0;
}
*/