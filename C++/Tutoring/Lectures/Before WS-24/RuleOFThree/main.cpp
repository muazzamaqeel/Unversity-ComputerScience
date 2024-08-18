#include <iostream>
using namespace std;

class Vector {
private:
    double* array; // Pointer to array storing vector elements
    int dimensions; // Number of dimensions in the vector

public:
    // Constructor: Initializes vector with specified dimensions and value
    Vector(int dimensions, double value) {
        this->dimensions = dimensions;
        array = new double[dimensions];
        for (int i = 0; i < dimensions; ++i) {
            array[i] = value;
        }
    }

    // Destructor: Frees memory allocated for array
    ~Vector() {
        delete[] array;
    }

    // Copy constructor: Creates a copy of another vector
    Vector(const Vector &other) {
        dimensions = other.dimensions;
        array = new double[dimensions];
        for(int i = 0; i < dimensions; i++) {
            array[i] = other.array[i];
        }
    }

    // Overloaded subscript operator for accessing vector elements
    double& operator[](int index) {
        return array[index];
    }

    // Assignment operator: Assigns the contents of another vector
    Vector& operator=(const Vector &other) {
        if (this != &other) {
            delete[] array;
            dimensions = other.dimensions;
            array = new double[dimensions];
            for (int i = 0; i < dimensions; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    // Friend function to overload << operator for outputting vector
    friend ostream& operator<<(ostream &out, const Vector &vector);
};

// Overloaded << operator to output vector elements
//We are able to access array variable
ostream &operator<<(ostream &out, const Vector &vector) {
    out << "(";
    for (int i = 0; i < vector.dimensions - 1; i++) {
        out << vector.array[i] << ", ";
    }
    out << vector.array[vector.dimensions - 1] << ")";
    return out;
}

// Main function
int main() {
    Vector vec(3, 1.0); // Create a vector with 3 dimensions, all elements initialized to 1.0
    cout << "vec: " << vec << endl; // Output the vector

    Vector vec2 = vec; // Create a copy of vec
    cout << "vec2 (copy of vec): " << vec2 << endl; // Output the copied vector

    Vector vec3(2, 2.0); // Create a vector with 2 dimensions, all elements initialized to 2.0
    vec3 = vec2; // Assign vec2 to vec3
    cout << "vec3 (assigned from vec2): " << vec3 << endl; // Output the assigned vector

    return 0;
}
