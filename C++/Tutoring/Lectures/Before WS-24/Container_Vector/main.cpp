#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Creating a vector of integers.
    std::vector<int> v = {7, 5, 16, 8};

    // Adding an element to the vector.
    v.push_back(25);
    v.push_back(13);

    // Iterating over the vector and printing its elements.
    std::cout << "Vector elements: ";
    for(int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // Sorting the vector.
    std::sort(v.begin(), v.end());

    // Printing the sorted vector.
    std::cout << "Sorted vector: ";
    for(int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    // Finding an element in the vector.
    auto it = std::find(v.begin(), v.end(), 16);
    if (it != v.end()) {
        std::cout << "Element " << *it << " found in the vector.\n";
    } else {
        std::cout << "Element not found in the vector.\n";
    }

    return 0;
}
