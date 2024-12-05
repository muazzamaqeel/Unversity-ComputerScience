#include <iostream>
using namespace std;

class Point{

public:
    int x,y;

    //Constructor
    Point(int x1=0, int y1=0):x(x1),y(y1){
    }

    Point operator+(Point& other){
        Point temp;
        //x is what p1 is in the main fucntion
        temp.x = x + other.x;
        temp.y = y + other.y;
        return temp;

    }
    Point operator-(Point& other){
        Point temp;
        //x is what p1 is in the main fucntion
        temp.x = x - other.x;
        temp.y = y - other.y;
        return temp;
    }
    // Overloads the << operator to print Point objects.
    // The reason we need to have this function as a friend becasue LHS is ostream and its not a member of Point class

     friend ostream& operator<<(ostream& os, Point& point){
        os << "(" << point.x << " Muazzam "<< point.y << ")";
        return os;
     }

};


int main() {
    //Point *p1=new Point();
    Point p1(3,4);
    Point p2(1,2);

    Point p3=p1+p2;
    Point p4=p1-p2;

    cout<<p3<<endl;
}
