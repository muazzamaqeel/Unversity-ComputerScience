#include <iostream>

class Team {
public:

    Team(){
        std::cout << "Constructor has been called!" << std::endl;
    }
    virtual ~Team() {  // Virtual destructor
        std::cout << "Destructor has been called!" << std::endl;
    }
};

int main() {
    Team obj;
    return 0;
}


