#include <iostream>
#include <vector>
#include <algorithm> // For std::transform and std::sort

// Functor to double a number
class Double {
public:
    int operator()(int x) const {
        return x * 2;
    }
};

int main() {
    // Step 1: Container (std::vector)
    std::vector<int> numbers = {10, 5, 8, 1, 7};

    // Step 2: Use std::sort (STL Algorithm) to sort the container
    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted numbers: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Step 3: Use std::transform (STL Algorithm) with a functor
    std::vector<int> doubledNumbers(numbers.size());
    Double functorobj;
    std::transform(numbers.begin(), numbers.end(), doubledNumbers.begin(), functorobj);
    //Or you can simply use Double() instead of functorobj
    //The reason why that works is because Double is a functor class and Double() creates a temporary object of the class Double



    std::cout << "Doubled numbers: ";
    for (std::vector<int>::iterator it = doubledNumbers.begin(); it != doubledNumbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
