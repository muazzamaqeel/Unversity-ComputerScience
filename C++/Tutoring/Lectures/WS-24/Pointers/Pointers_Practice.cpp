//1. Basic Pointer Declaration and Assignment

#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num; // Declare a pointer and point it to num
    
    // Print the address of num and its value using the pointer
    cout << "Address of num: " << ptr << endl;
    cout << "Value of num: " << *ptr << endl;
    return 0;
}




//2. Pointer Dereferencing
#include <iostream>
using namespace std;

int main() {
    int var = 20;
    int* ptr = &var; // Declare a pointer that points to var
    
    // Print the value of var using the pointer dereferencing
    cout << "Value of var: " << var << endl;
    cout << "Value of var using pointer: " << *ptr << endl;
    return 0;
}


//3. Pointer Arithmetic
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr; // Pointer pointing to the first element of arr
    
    // Use pointer arithmetic to print each element of the array
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }
    return 0;
}



//Fix the Code (4-6):
//4. Fix Null Pointer Issue
//Problem: The pointer ptr is uninitialized, causing undefined behavior.

#include <iostream>
using namespace std;

int main() {
    int num = 30;
    int* ptr = &num; // Initialize the pointer to point to num
    
    *ptr = 30; // Now this works correctly
    cout << "Value of num: " << *ptr << endl;
    return 0;
}

//5. Fix Segmentation Fault
//Problem: The pointer ptr is nullptr, dereferencing it causes a segmentation fault.


#include <iostream>
using namespace std;

int main() {
    int num = 50;
    int* ptr = &num; // Pointing to a valid address
    
    *ptr = 50; // Now this works correctly
    cout << "Value of num: " << *ptr << endl;
    return 0;
}


//6. Fix Double Pointer Dereferencing
//Problem: The code is incorrectly dereferencing a single pointer ptr1 instead of the double pointer ptr2.


#include <iostream>
using namespace std;

int main() {
    int num = 42;
    int* ptr1 = &num;
    int** ptr2 = &ptr1; // Double pointer
    
    // Correctly print num using ptr2
    cout << "Value of num using double pointer: " << **ptr2 << endl;
    return 0;
}


//
//Advanced (7-10):
//


//7. Dynamic Memory Allocation

#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int* arr = new int[size]; // Dynamically allocate memory for an array
    
    // Assign values and print them
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
        cout << "Element " << i << ": " << arr[i] << endl;
    }
    
    // Deallocate the memory
    delete[] arr;
    return 0;
}



// 8. Pointer to Function

#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    // Declare a pointer to the add function
    int (*funcPtr)(int, int) = &add;
    
    // Use the pointer to call the function and print the result
    int result = funcPtr(5, 10);
    cout << "Result of addition: " << result << endl;
    return 0;
}



// 9. Pointer to a Structure

#include <iostream>
#include <cstring>
using namespace std;

struct Person {
    char name[50];
    int age;
};

int main() {
    // Dynamically allocate memory for a Person
    Person* personPtr = new Person;
    
    // Assign values to name and age
    strcpy(personPtr->name, "John Doe");
    personPtr->age = 25;
    
    // Print the values using a pointer
    cout << "Name: " << personPtr->name << endl;
    cout << "Age: " << personPtr->age << endl;
    
    // Deallocate memory
    delete personPtr;
    return 0;
}



//10. Pointer to an Array of Pointers


#include <iostream>
using namespace std;

int main() {
    int* arr[5];  // Array of 5 integer pointers
    
    // Dynamically allocate memory for each element and assign values
    for (int i = 0; i < 5; i++) {
        arr[i] = new int;
        *arr[i] = i * 10; // Assign value to each pointer
    }
    
    // Print the values using the pointers
    for (int i = 0; i < 5; i++) {
        cout << "Value at arr[" << i << "]: " << *arr[i] << endl;
    }
    
    // Deallocate the memory
    for (int i = 0; i < 5; i++) {
        delete arr[i];
    }
    return 0;
}
