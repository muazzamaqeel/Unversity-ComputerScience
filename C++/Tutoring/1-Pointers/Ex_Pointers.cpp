// Exercises: Pointers
// Exercise 1

#include <iostream>
using namespace std;

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
	return 0;
	
}
