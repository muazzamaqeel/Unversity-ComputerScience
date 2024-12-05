//
// Created by muazz on 14/11/2024.
//

#include "friend.h"
#include <iostream>
using namespace std;

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Declare the friend function
    friend void printWidth(Box& b);
};

// Friend function definition
void printWidth(Box& b) {
    // Accessing the private member directly
    cout << "Width of the box: " << b.width << endl;
}

int main() {
    Box box(10.5);
    printWidth(box);  // This can access the private member 'width'
    return 0;
}
