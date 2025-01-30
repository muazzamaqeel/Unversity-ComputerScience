#include <iostream>
#include <utility> // For std::move
using namespace std;
class Data {
private:
    int data;
public:
    // Constructor
    Data(int value) : data(value) {
        std::cout << "Constructor called has been called" << endl;
    }

    // Copy Constructor
    Data(const Data& other) : data(other.data) {
        std::cout << "Copy Constructor called has been called" << endl;
    }

    /// <summary>
    /// Here we are using Move Constructor
    /// The main difference is with the keyword &&. This is an rvalue reference, 
    /// which is a reference that can only bind to temporary objects.
    /// </summary>
    /// <param name="other"></param>
    Data(Data&& other) : data(other.data) {
        other.data = 0; // Optional: Invalidate the moved-from object
        std::cout << "Move Constructor called has been called" << endl;
    }

    // Function that takes MoveExample by value
    void process(Data obj) {
        std::cout << "Processing object with data = " << obj.data << "\n";
    }

    // Function to display current data
    void display() {
        std::cout << "Current Data = " << data << "\n";
    }
};

int main() {

    Data a(10);

    //The Main Difference between Copy Constructor and Move Constructor is that Copy Constructor creates a new object by copying an existing object, 
    //while Move Constructor creates a new object by moving an existing object.
    a.process(a); // Copy constructor is called
    a.process(std::move(a)); // Move constructor is called


    a.display(); // a.data should be 0 after being moved

    //Whats missing here
    Data b = (a);

    return 0;
}
