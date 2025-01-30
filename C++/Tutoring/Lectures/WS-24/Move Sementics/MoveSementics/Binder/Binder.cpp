#include <iostream>
#include <vector>
#include <functional> // For std::greater

// Template class Binder that binds the second parameter of a binary operation
template<class Operation, class T>
class Binder {
public:
    // Constructor stores the binary operation and the second parameter
    Binder(const Operation& o, const T& t){
		op = o;
		y = t;
    }

    // Overload operator() to make Binder a unary function
    bool operator()(const T& x) const {
        return op(x, y);
    }

private:
    Operation op; // The binary operation (e.g., std::greater<int>())
    T y;          // The second operand is the bound value
};

int main() {
    // Create a vector of integers
    std::vector<int> numbers = { 15, 20, 25, 30, 35 };

    // Create a Binder that binds the second parameter to 20 using std::greater<int>

    Binder<std::greater<int>, int> isGreaterThan20(std::greater<int>(), 20);


    for (int i = 0; i < numbers.size(); ++i) {
        int num = numbers[i];
        std::cout << num << " > 20? ";
        if (isGreaterThan20(num))
            std::cout << "True\n";
        else
            std::cout << "False\n";
    }

    return 0;
}
