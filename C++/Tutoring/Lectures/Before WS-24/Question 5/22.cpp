#Practice


#include <iostream>
#include <string>
#include <vector>

//Contructors

class Point {

private:
    double* components; // Dynamic array to store coordinates
    int len; // Number of dimensions

//Purpose: Initializes a Point object with agiven number of dimensions.
//Details: Allocates a dynamic array of doubles to store the coordinates.

public:
    Point(int length) {
        len=length;
        components = new double[len];
    }
};
//Purpose: Cleans up the dynamically allocated array when a 
//Point object is destroyed.
//Details: Deletes the array to free memory.
//Destructors
~Point(){
    if(components){
        delete[] components;
    }

//Purpose: Assigns one Point object to another.
//Details:
//Checks for self-assignment.
//Throws an exception if the dimensions do not match.
//Copies the components if the dimensions are compatible.
    Point& operator=(const Point& other) {
        if (this == &other) {
            return *this; // Handle self-assignment
        }
        if (other.len > this->len) {
            throw Error("Dimension mismatch");
        }else{
            for (int i = 0; i < other.len; ++i) {
                components[i] = other.components[i];
            }
        }
    }
//Purpose: Allows access to individual components of the Point 
        //using array-like syntax.
//Details: Throws an exception if the requested dimension is out of bounds.

double& operator[](int dim) {
        if (dim < 0 || dim >= len) {
            throw Error("Out of bounds");
        } 
        return components[dim];

}


//Purpose: Allows a Point object to be output using <<.
//Details: Utilizes the toString method to format the output.
std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << p.toString();
    return os;
}

std::string toString() const {
    std::stringstream buffer;
    buffer << "(";
    for (int i = 0; i < len; ++i) {
        buffer << components[i];
    }
    buffer << ")";
    return buffer.str();
}


void test() {
    Point x(1); // 1-dimensional
    Point q(3); // 3-dimensional
    try {
        Point p = q;
        std::cout << x << std::endl;
        std::cout << p << std::endl;
        std::cout << q << std::endl;
        
        p[0] = 100.0;
        p[1] = 5.0; 
        x[0] += p[0];
        
        std::cout << x << std::endl;
        std::cout << p << std::endl;
        std::cout << q << std::endl;
        
        Point p1(2), p2(2);
        
        p1 = p2; // o.k.
        q = p1; // o.k.
        p2 = q; // Error
        
    } catch (std::exception& e) {
        std::cout << e.what();
    }


    int main() {
    test(); // Run the test function
    return 0;
}
}
















