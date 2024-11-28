#include <iostream>

class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}


    /// Overloads the + operator to add two Point objects.
    /// 
    /// LHS (Left-Hand Side): The Point object invoking the operator (e.g., p1 in p1 + p2).
    /// RHS (Right-Hand Side): The Point object passed as an argument to the operator (e.g., p2 in p1 + p2).
    /// 
    /// Functionality:
    /// - Adds the x-coordinate of the invoking (LHS) object to the x-coordinate of the argument (RHS) object.
    /// - Adds the y-coordinate of the invoking (LHS) object to the y-coordinate of the argument (RHS) object.
    /// - Returns a new Point object representing the sum of the two points.
    ///
    /// Example:
    /// Point p1(3, 4), p2(1, 2);
    /// Point p3 = p1 + p2; // Result: p3 = (3 + 1, 4 + 2) = (4, 6)
    
    
    //p1.operator+(p2);
	//Above means p1 is LHS and p2 is RHS


    Point operator+(Point& other){

        Point temp;
		temp.x = x + other.x;
		temp.y = y + other.y;


        return temp;
    }

    // Method to display the point
    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};


int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2;  // Using the overloaded + operator

    std::cout << "Point 1: ";
    p1.display();

    std::cout << "Point 2: ";
    p2.display();

    std::cout << "Point 3 (p1 + p2): ";
    p3.display();

    return 0;
}
