#include <iostream>
using namespace std;

class Box {
public:
    int length;

    Box(){};

    // Constructor to initialize the length
    Box(int len) {
        length = len;
    }

    // Overloading the + operator to add two box lengths

    ///int val: This declares a local variable val of type int.
    ///length: This is the member variable of the current object (the left operand of the +), which stores the length of the box.
    ///other.length: This accesses the length member variable of the other Box object (the right operand of the +).

    Box operator+(const Box& other) const {
        int val = length + other.length;
        return val;

    }
    // Overloading the == operator to compare two box lengths
    bool operator==(const Box& other) const {

        if (length == other.length){
        return true;
        };

        return false;
    }
};

int main() {
    Box box1(10);
    Box box2(10);
    Box box3;
    box3 = box1 + box2; // Uses overloaded + operator

    cout << "Length of box1: " << box1.length << endl;
    cout << "Length of box2: " << box2.length << endl;
    cout << "Combined length of box1 and box2: " << box3.length << endl;

    // Check if two boxes are of the same length
    if (box1 == box2) {
        cout << "Box1 and Box2 are of the same length." << endl;
    } else {
        cout << "Box1 and Box2 are not of the same length." << endl;
    }

    return 0;
}
