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
    A() { cout << " cA"; }
    A(A& a) { cout << " copyA"; }
    ~A() { cout << " ~A"; }
    void doSomething() { cout << " doA"; }
};

class B : public Top {
private:
    Top* ptrTop;
    A objA;
public:
    B() { cout << " cB"; }
    B(B& a) { cout << " copyB"; }
    ~B() { cout << " ~B"; }
    Top* getptrTop() { return ptrTop; }
    void setptrTop(Top* t) { ptrTop = t; }
    A getobjA() { return objA; }
    void setA(A a) { objA = a; }
};

void test(){
    Top t[3];
    cout<<""<<endl;
    A a1;
    cout<<""<<endl;
    B* b1 = new B();
    cout<<""<<endl;
    t[1] = a1;
    t[2] = *b1;
    A a2 = a1;
    b1->setptrTop(&a2);
    t[1].doSomething();
    t[2].doSomething();
    a2.doSomething();
    b1->doSomething();
    b1->getptrTop()->doSomething();
    b1->getobjA().doSomething();
    delete b1;
}

int main() {
    test();
    return 0;
}
