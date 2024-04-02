// Exercises: Pointers
// Exercise 1

#include <iostream>
using namespace std;




void increment(int* ptr) {
    (*ptr)++; // Incrementing the value of 'ptr' 
	//*ptr=*ptr+1;
	
}


int main(){

/*Exercise 1
Write a program that asks the user to enter integers as inputs to be stored in the variables 'a' and 'b' respectively.
There are also two integer pointers named ptrA and ptrB. Assign the values of 'a' and 'b' to ptrA and ptrB respectively, and display them
*/


//Exercise 2
	char str[] = "A string.";
	char *pc = str;

	cout << str[0] <<' '<< *pc <<' '<<pc[3]<<"\n";
	
	pc =pc+3;
	
	cout <<*pc<<' '<< pc[2] <<' '<< pc[5];


//Exercise 3
	int num = 10;
    std::cout << "Before incrementing: " << num << std::endl;
    increment(&num); // Passing address of 'num' to the function
    std::cout << "After incrementing: " << num << std::endl;

	return 0;

}


