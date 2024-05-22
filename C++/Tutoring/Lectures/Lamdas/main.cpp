#include <iostream>


///Capturing by Value [x, y]
///When capturing by value, the lambda function makes a copy of the variables.
///Changes made to these copies inside the lambda do not affect the original variables outside the lambda.
/*
int main() {
    int x = 10;
    int y = 20;

    // Capture by value
    auto addByValue = [x, y]() -> int {
        return x + y;
    };

    std::cout << "Sum by value: " << addByValue() << std::endl;  // Output: Sum by value: 30
    std::cout <<x<<std::endl;
    std::cout <<y<<std::endl;


    return 0;
}

*/
/*
///Parameters in the lambda function's parameter list () are similar to parameters in regular functions.
// These parameters are passed to the lambda when it is called, and they can be used within the lambda's body.
#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // Capture by reference
    auto addByReference = [&x, &y]() -> int {
        x = x + 1;  // Modifying x
        y = y + 1;  // Modifying y
        return x + y;
    };

    std::cout << "Sum by reference: " << addByReference() << std::endl;  // Output: Sum by reference: 32
    std::cout << "Modified x: " << x<<std::endl;  // Output: Modified x: 11
    std::cout << "Modified y: " << y<<std::endl;  // Modified y: 21

    return 0;
}

*/

///Parameters in the lambda function's parameter list () are similar to parameters in regular functions.
///These parameters are passed to the lambda when it is called, and they can be used within the lambda's body.
#include <iostream>
int main() {
    // Define a lambda function that takes two parameters
    auto add = [](int a, int b) -> int {
        return a + b;
    };
    // Call the lambda function with arguments
    int result = add(2, 3);
    // Print the result
    std::cout << "Sum: " << result << std::endl;  // Output: Sum: 5
    //std::cout << a <<std::endl;
    //std::cout << b <<std::endl;
    return 0;
}

