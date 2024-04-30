/*



//////////////////////////////
//////////////////////////////
Dive into C++ STL Containers
//////////////////////////////
//////////////////////////////


### Question 1: Vector
**Describe the characteristics of a `std::vector` in C++. Include its underlying data structure, performance characteristics for operations such as insertion, deletion, and random access, and typical use cases where a vector is preferred over other types of containers.**

### Question 2: List
**Explain how a `std::list` works in C++. Discuss its internal structure, how it handles operations like insertion and deletion, and the scenarios where a list might be more advantageous than other container types.**

### Question 3: Map
**Define a `std::map` and its typical applications in C++. Elaborate on its internal data structure, performance for various operations such as searching and inserting, and how it handles key-value pairs.**

### Question 4: Set
**What is a `std::set` and how is it used in C++? Discuss the underlying mechanism, typical operations, and why a set might be chosen over other similar container types.**

### Question 5: Multiset
**Describe the `std::multiset` container in C++. Explain how it differs from `std::set`, its handling of duplicates, and situations where a multiset is particularly useful.**

### Question 6: Multimap
**Discuss the properties and uses of a `std::multimap` in C++. Include how it manages multiple values for a single key and compare its functionality and performance with `std::map`.**

### Question 7: Unordered Map
**Explain the concept and advantages of an `std::unordered_map`. Discuss how it differs from a `std::map` in terms of internal structure, performance, and typical use cases.**

### Question 8: Unordered Set
**Define `std::unordered_set` and discuss its characteristics. Explain how its internal hashing mechanism impacts performance and in what scenarios it might be preferable to a `std::set`.**

### Question 9: Unordered Multimap
**Describe the functionality of `std::unordered_multimap`. Compare its performance and use cases to `std::unordered_map` and discuss how it handles multiple entries for the same key.**

### Question 10: Unordered Multiset
**What is an `std::unordered_multiset` and how does it operate? Explain its underlying structure, performance considerations, and scenarios where it might be used over `std::unordered_set`.**




//////////////////////////////
//////////////////////////////
Coding Questions
//////////////////////////////
//////////////////////////////


### Coding Question 1: Vector
**Write a C++ program to create a `std::vector` of integers. Add five integers to it from user input, then print the integers in reverse order.**

### Coding Question 2: List
**Develop a C++ program that initializes a `std::list` of strings with three names. Allow the user to add two more names to the front of the list, then display all the names in the list.**

### Coding Question 3: Map
**Create a C++ program that constructs a `std::map` where the keys are countries and the values are capitals. Populate this map with three countries and their capitals, then allow the user to query the capital of a country.**

### Coding Question 4: Set
**Implement a C++ program that initializes a `std::set` of characters and continuously allows the user to add characters until they enter '0'. Finally, print all the characters in the set in ascending order.**

### Coding Question 5: Multiset
**Write a C++ program to demonstrate the use of `std::multiset`. The program should allow users to add elements to a multiset of doubles and then display all elements of the multiset.**

### Coding Question 6: Multimap
**Develop a C++ application using `std::multimap` to simulate a simple phone book where a person's name can have multiple phone numbers. Allow the user to enter three names, each with two phone numbers, and then display the phone book entries.**

### Coding Question 7: Unordered Map
**Create a C++ program that uses an `std::unordered_map` to store the number of times a word appears in the input. Take five words from user input, update their counts in the map, and then display the contents of the map.**

### Coding Question 8: Unordered Set
**Implement a simple C++ program using `std::unordered_set` to remove duplicates from an array of integers given by the user. Print the result after all elements have been added to the set.**

### Coding Question 9: Unordered Multimap
**Write a C++ program that uses an `std::unordered_multimap` to map a number to its occurrences in an array. Populate the map using user input for five numbers and then display the number and its count.**

### Coding Question 10: Unordered Multiset
**Develop a C++ program that allows the user to enter integers into an `std::unordered_multiset` until they enter the number -1. Then, print each unique number and how many times it appeared.**




Advanced Question --- Functional Obejcts

1. Write a C++ program that uses a functor to compare two integers and returns the larger of the two. Demonstrate this functor with user input.N

2.  FIX CODE:
*/


#include <iostream>

// Define a functor
class Compare {
private:
    int operator(int a) {
        return (a > b) ? a : b;
    }
};

int main() {
    Compare cmp;  // Create an instance of the Compare functor
    int x, y;

    std::cout << "Enter two integers:\n";
    std::cin >> x >> y;

    // Use the functor to find and print the larger of two integers
    std::cout << "The larger value is: " << cmp(x, y) << std::endl;

    return 0;
}

/*
//////////////////////////////
//////////////////////////////
Missing Code
//////////////////////////////
//////////////////////////////
*/

#include <iostream>

class Doubler {
public:
    // TODO: Implement the function operator to double the value of an integer
    int operator()(int x);
};

int main() {
    Doubler dbl;  // Create an instance of the Doubler functor
    int input;

    std::cout << "Enter an integer:\n";
    std::cin >> input;

    // Use the functor to double the value of the input
    int result = dbl(input);

    std::cout << "The doubled value is: " << result << std::endl;

    return 0;
}





