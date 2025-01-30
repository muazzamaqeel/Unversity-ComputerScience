#include <iostream>
#include <utility> // For std::move
using namespace std;
class Data {
private:
    int data;
public:
    // Constructor
    Data(int value) : data(value) {
        std::cout << "Constructor has been called" << endl;
    }

    // Copy Assignment Operator
    Data& operator=(Data& other) {
        data = other.data;
        std::cout << "Copy Assignment Operator has been called" << endl;
        return *this;
    }
    // Move Assignment Operator
    Data& operator=(Data&& other) {
        data = other.data;
        std::cout << "Move Assignment Operator" << endl;
        return *this;
    }
    // Destructor
    ~Data() {
        std::cout << "Destructor has been called" << endl;
    }
};

int main() {

    Data a(10);
    Data b(20);

    b = a; // Copy assignment operator is called
    
	//Whats missing here?
    b = a;

    return 0;
}
