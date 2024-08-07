//Exercises: Pointers


#include <iostream>
using namespace std;

void increment(int* ptr) {
    (*ptr)++; // Incrementing the value of 'ptr' 
	//*ptr=*ptr+1;

}



int main(){

/////////////////////////////////////////////////////Weekly Ex./////////////////////////////////////////////////////

/*Exercise 1
Write a program that asks the user to enter integers as inputs to be stored in the variables 'a' and 'b' respectively.
There are also two integer pointers named ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, and display them
*/

//Exercise 2: Write a program in C++ to add two numbers using pointers.

//Exercise 3: Write a program in C++ to store n elements in an array and print the elements using a pointer.

//Exercise 4: Write a program in C++ to calculate the length of a string using a pointer.

/* Exercise 5:
Allocate two pointers on the heap. Each pointer should reference its own variable.
Pass these pointers to a function. The function's task is to determine which pointer refers to a variable with the larger value.
After the function execution is complete, deallocate the memory for both pointers on the heap to prevent memory leaks.
*/

/*Exercise 6:
	Show an code example for the following concepts (Feel free to play around - There are no boundries for this question)
	1. Incrementing a Pointer
	2. Decrementing a Pointer
	3. Comparing the values of what the two pointers are holding

*/

//Advance
//Exercise 1. 


//Write a program in C++ to sort an array using a pointer.
//int data[]={111,4,1,22,77,11,22};

x


//Exercise 2. 
//Write a C++ program to demonstrate how a function returns a pointer.

/*
Exercise 3.
Accessing Variable Value Through Double Pointers in C++, Consider you have an integer variable 
num in a C++ program, initialized with the value 10. You are also given a pointer ptr that points to num,
and another pointer pptr that points to ptr.
*/

































/////////////////////////////////////////////////////Lecture/////////////////////////////////////////////////////






//Exercise 2
	int num = 20;
	int *pc1;
    std::cout << "Before incrementing: " << num << std::endl;
    increment(pc1); // Passing address of 'num' to the function
    std::cout << "After incrementing: " << num << std::endl;




//Exercise 3
	char str[] = "A string.";
	char *pc = str;

	//cout << str[0] <<' '<< *pc <<' '<<pc[3]<<"\n";
	pc =pc+3;
	//cout <<*pc<<' '<< pc[2] <<' '<< pc[5];




//Exercise 4
	int temp = 20; 
    int* ptr = new int(temp); // 'new' allocates memory for an integer and initializes it to 10
    std::cout << "Value of *ptr: " << *ptr << std::endl; // Access the value at the memory address stored in ptr

	int temp1 = 30; 
    int* ptr1 = new int();
    ptr1 = &temp1;
	std::cout << "Value of *ptr1: " << *ptr1 << std::endl;





	int data[]={111,4,1,22,77,11,22};

	return 0;

}
























//    delete ptr; // Free the memory allocated for ptr
  //  ptr = nullptr; // It's a good practice to set the pointer to nullptr after deleting its heap memory

