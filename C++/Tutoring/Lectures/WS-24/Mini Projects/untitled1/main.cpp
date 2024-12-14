#include <iostream>
#include <map>
using namespace std;

class Multiply{
    int factor;  // State (multiplier value)
public:
    //Constructor
    Multiply(int f) {
        factor=f;
    }
    //Operator Overloading
    int operator()(int x){
        return factor*x;
    }
};
int main() {
    Multiply multiplyBy3(3);

    //Factor varaible is already 3
    cout << multiplyBy3(1);
    //We multiply the Factor var with value x
}
