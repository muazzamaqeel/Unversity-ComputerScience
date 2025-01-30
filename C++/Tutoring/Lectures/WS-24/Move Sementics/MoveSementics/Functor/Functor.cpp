// Functor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//This class is a functor
class Add {
public:
	int operator()(int a, int b) {
		return a + b;
	}
};


int main()
{
	Add add;
	cout << add(2, 2) << endl;
	auto a = add(1, 2);
	cout << a << endl;


	return 0;
}
