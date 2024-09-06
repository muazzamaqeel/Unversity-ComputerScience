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
    std::cout << "\n";

   
   
   
    // Example 2: Pointer Arithmetic
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // Point to the first element of the array
    std::cout << "Pointer Arithmetic: ";
    for(int i = 0; i < 5; i++) {
        std::cout << *(p + i) << " "; // Use pointer arithmetic to access array elements
    }
    std::cout << "\n";
    std::cout << "\n";

   
   
   
    // Example 3: Pointers and Strings
    const char *str[] = {"Postion 0","Postion 1"};
    std::cout << "Pointers and Strings: " << str[1] << "\n";
    std::cout << "\n";
   
   
   
    // Example 4: Pointers to Pointers
    int **pptr = &ip; // Pointer to a pointer
    std::cout << "Pointers to Pointers: Value available at **pptr = " << **pptr << "\n";
    std::cout << "\n";
    std::cout << "\n";

    
    
    
    //Example 5: Dynamic Memory Allocation
    int n = 5;
    // Dynamically allocate an array of ints
    int *dynamicArr = new int[n]; 
    // Assign values
    for(int i = 0; i < n; i++) {
        dynamicArr[i] = i + 100;
    }
    // Print the values
    std::cout << "Dynamic Memory Allocation: ";
    std::cout << "\n";
    for(int i = 0; i < n; i++) {
        std::cout << dynamicArr[i] <<std::endl;
    }
    std::cout << "\n";
    // Free the allocated memory
    delete[] dynamicArr; 




    // Example 6: Function Pointers
    void (*functionPtr)() = &HelloWorld; // Declaration and initialization of a function pointer
    std::cout << "Function Pointers: Calling HelloWorld... ";
    (*functionPtr)(); // Calling function using pointer

    return 0;
}
