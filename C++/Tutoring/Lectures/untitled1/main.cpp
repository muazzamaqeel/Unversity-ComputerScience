#include <iostream>
using namespace std;

class Top {
public:
    Top()          { cout << " cTop" << endl; }
    Top(Top& a)    { cout << " copyTop" << endl; }
    ~Top()         { cout << " ~Top" << endl; }
    void doSomething() { cout << " doTop" << endl; }
    void setptrTop(Top* t) {cout << " WRONG ONE" << endl;}

};

class A : public Top {
public:
    A()            { cout << " cA" << endl; }
    A(A& a)        { cout << " copyA" << endl; }
    ~A()           { cout << " ~A" << endl; }
    void doSomething() { cout << " doA" << endl; }
};

class B : public Top {
private:
    Top* ptrTop;
    A objA;
public:
    B()            { cout << " cB" << endl; }
    B(B& a)        { cout << " copyB" << endl; }
    ~B()           { cout << " ~B" << endl; }
    Top* getptrTop() { return ptrTop; }
    void setptrTop(Top* t) { ptrTop = t; }
    A getobjA() { return objA; }
    void setA(A a) { objA = a; }
};

void test() {
    Top t[3];
    A a1;
    B* b1 = new B();
    t[1] = a1;
    t[2] = *b1;
    A a2 = a1;
    cout<<"-----------------------------------"<<endl;
    cout<<"----------------1-------------------"<<endl;
    b1->setptrTop(&a2);       //Nothibg got pribted out here
    cout<<"-----------------------------------"<<endl;
    cout<<"-----------------------------------"<<endl;


    t[1].doSomething();
    t[2].doSomething();
    a2.doSomething();

    cout<<"-----------------------------------"<<endl;
    cout<<"----------------2-------------------"<<endl;
    b1->doSomething();
    cout<<"-----------------------------------"<<endl;
    cout<<"-----------------------------------"<<endl;

    b1->getptrTop()->doSomething();
    b1->getobjA().doSomething();
    delete b1;
}

int main() {
    test();
    return 0;
}
