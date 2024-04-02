#include <iostream>
#include <stdlib.h>

// Correctly declare the HelloWorld function before main()
void HelloWorld() {
    std::cout << "Hello, World!\n";
}

int main() {
    // Example 1: Basic Pointer Usage
    int var = 20;
    int *ip = &var;
    std::cout << "Basic Pointer Usage: Value of *ip = " << *ip << "\n";

   
   
   
    // Example 2: Pointer Arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // Point to the first element of the array
    std::cout << "Pointer Arithmetic: ";
    for(int i = 0; i < 5; i++) {
        std::cout << *(p + i) << " "; // Use pointer arithmetic to access array elements
    }
    std::cout << "\n";

   
   
   
    // Example 3: Pointers and Strings
    const char *str = "Hello, World!";
    std::cout << "Pointers and Strings: " << str << "\n";

   
   
   
    // Example 4: Pointers to Pointers
    int **pptr = &ip; // Pointer to a pointer
    std::cout << "Pointers to Pointers: Value available at **pptr = " << **pptr << "\n";

    
    
    
    // Example 5: Dynamic Memory Allocation
    int n = 5;
    int *dynamicArr = (int*)malloc(n * sizeof(int)); // Dynamically allocated array
    if(dynamicArr == NULL) {
        std::cout << "Memory allocation failed\n";
        return 1; // Exit if memory allocation failed
    }
    for(int i = 0; i < n; i++) {
        dynamicArr[i] = i + 100; // Assign values
    }
    std::cout << "Dynamic Memory Allocation: ";
    for(int i = 0; i < n; i++) {
        std::cout << dynamicArr[i] << " ";
    }
    std::cout << "\n";
    free(dynamicArr); 




    // Example 6: Function Pointers
    void (*functionPtr)() = &HelloWorld; // Declaration and initialization of a function pointer
    std::cout << "Function Pointers: Calling HelloWorld... ";
    (*functionPtr)(); // Calling function using pointer

    return 0;
}
