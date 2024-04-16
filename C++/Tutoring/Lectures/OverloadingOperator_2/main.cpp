#include "mystring.h"
#include <iostream>
#include <cassert>

using namespace stringexercise;

int main() {
    // Test default constructor
    mystring s1;
    assert(s1.is_empty());

    // Test constructor from C-string
    mystring s2("Hello");
    assert(s2.length() == 5);
    assert(std::string(s2.c_str()) == "Hello");

    // Test copy constructor
    mystring s3(s2);
    assert(s3.length() == 5);
    assert(std::string(s3.c_str()) == "Hello");

    // Test assignment operator
    s1 = s3;
    assert(s1.length() == 5);
    assert(std::string(s1.c_str()) == "Hello");

    // Test index operator for access
    assert(s1[0] == 'H');
    assert(s1[4] == 'o');

    // Test index operator for modification
    s1[1] = 'a';
    assert(s1[1] == 'a');
    assert(std::string(s1.c_str()) == "Hallo");

    // Test operator+= with mystring
    s1 += s3;
    assert(s1.length() == 10);
    assert(std::string(s1.c_str()) == "HalloHello");

    // Test operator+= with C-string
    s1 += " World";
    assert(s1.length() == 16);
    assert(std::string(s1.c_str()) == "HalloHello World");

    // Test operator+= with char
    s1 += '!';
    assert(s1.length() == 17);
    assert(std::string(s1.c_str()) == "HalloHello World!");

    // Test output stream operator
    std::cout << "Output of s1: " << s1 << std::endl;

    // Test input stream operator
    std::cout << "Enter a string for s2: ";
    std::cin >> s2;
    std::cout << "You entered: " << s2 << std::endl;

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
