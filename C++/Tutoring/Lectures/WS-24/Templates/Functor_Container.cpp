#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functor class
class Multiply {
    int factor;  // State (multiplier value)
public:
    Multiply(int f) : factor(f) {}  // Constructor to initialize the multiplier

    // Overloaded () operator
    int operator()(int x) const {
        return x * factor;
    }
};

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> results(numbers.size());

    Multiply multiplyBy3(3);  // Create a functor object with factor = 3

    // Apply the functor to each element using std::transform
    transform(numbers.begin(), numbers.end(), results.begin(), multiplyBy3);

    // Print the results
    for (int x : results)
        cout << x << " ";
    return 0;
}
