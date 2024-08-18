#include <iostream>
using namespace std;

class Top {
public:
    Top() { cout << " cTop"; }
    Top(Top& a) { cout << " copyTop"; }
    ~Top() { cout << " ~Top"; }
     void doSomething() { cout << " doTop"; }
};

class A : public Top {
public:
    A() { cout << " cA"<<endl; }
    A(A& a) { cout << " copyA"<<endl; }
    ~A() { cout << " ~A"<<endl; }
    void doSomething() { cout << " doA"<<endl; }
};

class B : public Top {
private:
    Top* ptrTop;
    A objA;
public:
    B() { cout << " cB"<<endl; }
    B(B& a) { cout << " copyB"<<endl; }
    ~B() { cout << " ~B"; }

    Top* getptrTop() { return ptrTop; }
    void setptrTop(Top* t) { ptrTop = t; }

    A getobjA() { return objA; }
    void setA(A a) { objA = a; }
    void doSomething() { cout << " CORRECT ONE"; }

};


void test() {

    B* b1;
    b1->doSomething();


}

int main() {
    test();
    return 0;
}
