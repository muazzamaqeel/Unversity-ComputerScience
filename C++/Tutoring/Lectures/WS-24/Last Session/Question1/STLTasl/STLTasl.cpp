// STLTasl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


// Data Entry
//a. Prompt the user to enter the number of books they wish to add to the collection.
//b. For each book, prompt the user to enter the name of the book
//      b.1) Optional--------Allow the user to enter the book name with spaces (e.g., "Harry Potter ")
//c. Store all the entered book names in a std::vector<std::string> container

// Serach Funcitonality
//a. Now prompt the user to enter the name of a book they want to search for in the collection.
//b. Utilize an appropriate STL algorithm to determine if the entered book name exists in the vector.
//c. Inform the user whether the book was found or not.

// Data Transformation and Display
//a.Transfer all the book names from the vector to a std::map<int, std::string>, where the key is a unique Book ID, and the value is the book name itself.
//b.Use an iterator to traverse the multimap and print out all the book names in the collection


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // 1. Data Entry
    std::vector<std::string> bookCollection;
    int numberOfBooks;

    // a. Prompt the user to enter the number of books
    std::cout << "Enter the number of books you wish to add to the collection: ";
    std::cin >> numberOfBooks;

    // Validate the input
    while (numberOfBooks < 0) {
        std::cout << "Please enter a positive number: ";
        std::cin >> numberOfBooks;
    }

	// Clear the input buffer
    // After reading an integer (numberOfBooks), a newline (\n) remains in the input buffer, 
    // which causes std::getline() to consume it instead of waiting for user input. 
    std::cin.ignore();



    // b. For each book, prompt the user to enter the name of the book
    string bookName;
    for (int i = 0; i < numberOfBooks; ++i) {
        std::cout << "Enter the name of book " << i << ": ";
        std::getline(std::cin, bookName);
        //std::cin >> bookName;

        // c. Store the entered book name in the vector
        bookCollection.push_back(bookName);
    }

    // 2. Search Functionality
    std::cout << "\nEnter the name of the book you want to search for: ";
    std::cin >> bookName;

    // b. Check if the book exists in the vector
    bool found = false;
    for (int i = 0; i < bookCollection.size(); ++i) {
        if (bookCollection[i] == bookName) {
            found = true;
            break;
        }
    }

    // c. Inform the user whether the book was found or not
    if (found) {
        std::cout << "The book \"" << bookName << "\" was found in the collection.\n";
    }
    else {
        std::cout << "The book \"" << bookName << "\" was NOT found in the collection.\n";
    }

    // 3. Data Transformation and Display

    // a. Transfer all book names to a std::map<int, std::string> with unique Book IDs
    std::map<int, std::string> bookMap;
    for (int i = 0; i < bookCollection.size(); ++i) {
        // Book IDs start from 1
        bookMap[i + 1] = bookCollection[i];
    }

	std::map<int, std::string>::iterator it;
	for (it = bookMap.begin(); it != bookMap.end(); ++it) {
		std::cout << "Book ID: " << it->first << " - Book Name: " << it->second << std::endl;
	}

    return 0;
}
