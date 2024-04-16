#include <iostream>
using namespace std;

class Deep {
public:
    int* data;

    Deep(int d) {
        data = new int(d); // Allocate and initialize memory
    }

    // Deep copy constructor simplified further
    Deep(const Deep& d1) {
        int value = *d1.data;    // Retrieve the value from the source's data
        data = new int(value);       // Allocate new memory and copy the value
    }

    ~Deep() {
        delete data; // Free the allocated memory
    }
};

int main() {
    Deep d1(5);
    Deep d2 = d1; // Deep copy
    *d1.data = 10; // Does not change d2
    cout << "d2 data: " << *d2.data << endl; // Output will be 5
}
