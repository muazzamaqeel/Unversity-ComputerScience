#include <iostream>
using namespace std;



//NOT THE DATA JUST THE ADDRESS

class Shallow {
public:
    int* data;

    Shallow(int d) {
        data = new int(d); // Allocate memory
    }

    // Shallow copy constructor without initializer list
    Shallow(const Shallow& s1) {
        data = s1.data; // Copy the pointer (shallow copy)
    }

    ~Shallow() {
        delete data; // Free memory
    }
};

int main() {
    Shallow s1(5);
    Shallow s2 = s1; // Shallow copy

    *s1.data = 10; // Changes both s1 and s2
    cout << "s2 data: " << *s2.data << endl; // Output will be 10


    *s2.data = 20; // Changes both s1 and s2
    cout << "s1 data: " << *s1.data << endl; // Output will be 10
}
