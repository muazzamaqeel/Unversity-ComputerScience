#include <iostream>

class Base {
public:
   virtual void show() {
        std::cout << "Base class show function called." << std::endl;
    }
     virtual ~Base() {}
};

class Derived : public Base {
public:
    void show() override{
        std::cout << "Derived class show function called." << std::endl;
    }
};

int main() {

    //Case
    Base Obj4;
    std::cout<<"For a Base Object:"<<std::endl;
    Obj4.show();
    std::cout<<"------------------------**---------------------------"<<std::endl;


    //Case
    Derived Obj3;
    std::cout<<"For a Derived Object:"<<std::endl;
    Obj3.show();
    std::cout<<"------------------------**---------------------------"<<std::endl;


    //Case

    Base *Obj2 = new Base;
    std::cout<<"For a Base Pointer Initialized with the Base Class:"<<std::endl;
    Obj2->show();
    std::cout<<"------------------------**---------------------------"<<std::endl;


    //Case

    Base *Obj1 = new Derived;
    std::cout<<"For a Base Pointer Initialized with the Derived Class:"<<std::endl;
    Obj1->show();
    std::cout<<"------------------------**---------------------------"<<std::endl;


    return 0;
}
































/*
 *
    //Case

    Base *Obj5;
    std::cout<<"Obj5--For a Base Pointer:"<<std::endl;
    Obj5->show();
    std::cout<<"------------------------**---------------------------"<<std::endl;


    //Case

    Derived *Obj6;
    std::cout<<"Obj6--For a Derived Pointer:"<<std::endl;
    Obj6->show();
    std::cout<<"------------------------**---------------------------"<<std::endl;

 */
