#include <iostream>

// Define a class that will act as a functor
//So if we don't overload the () Operator, we cannot create objects as functions,
// In order words Functional Objects
class Incrementer {
private:
    int increment_; // State: value to add to each call

public:
    // Constructor to initialize the increment value
    explicit Incrementer(int increment){
        increment_= increment;
    }

    // Overload the operator() to make this a functor
    int operator()(int value) const {
        return value + increment_;
    }


};

int main() {
    Incrementer addFive(5); // Create a functor that adds 5
    Incrementer addTen(10); // Create a functor that adds 10


    std::cout << "addFive(10): " << addFive(10) << std::endl; // Outputs: 15
    std::cout << "addTen(10): " << addTen(10) << std::endl;   // Outputs: 20

    return 0;
}
