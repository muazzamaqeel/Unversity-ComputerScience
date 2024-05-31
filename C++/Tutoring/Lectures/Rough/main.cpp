#include <iostream>
// Base class
class Top {
public:
    Top() {
        std::cout << "Top's Constructor" << std::endl;
    }
    Top(Top &T){
        std::cout << "Top's Copy Constructor has been called" << std::endl;
    }
};
// Derived class
class A : public Top {
public:
    A() {
        std::cout << "A's Constructor" << std::endl;
    }
    A(A &a){
        std::cout << "A's Copy Constructor has been called" << std::endl;
    }
    void test(Top &Top) {
        std::cout << "A's method" << std::endl;
    }
};
int main() {
    A obj;
    Top Top_obj;

    obj.test(Top_obj);
    return 0;
}