#include <iostream>
using namespace std;

class Part {
public:
    Part() { cout << " cPart" << endl; }
    Part(const Part& a) { cout << " copyPart" << endl; }
    ~Part() { cout << " ~Part" << endl; }
};

class Base {
private:
    Part p;  // Composition
public:
    Base() { cout << " cBase" << endl; }
    Base(const Base& b) { cout << " copyBase" << endl; }
    virtual ~Base() { cout << " ~Base" << endl; }

    void method1(Base b) { cout << " m1Base" << endl; }
};

class Child : public Base {
private:
    Part* ptrP;
public:
    Child() { cout << " cChild" << endl; ptrP = 0; }
    Child(const Child& c) { cout << " copyChild" << endl; ptrP = c.ptrP; }
    ~Child() { cout << " ~Child" << endl; if (ptrP) delete ptrP; }

    void method1(Base b) { cout << " m1Child" << endl; }
    void method1(Base* b) { cout << " m1_Child" << endl; b->method1(*b); }
    void method2() { cout << " m2Child" << endl; ptrP = new Part(); }
};

void test() {
    Child c1;                           // Output: cPart cBase cChild
    Child c2 = c1;                      // Output: cPart cBase copyChild
    Base b1;                            // Output: cPart cBase
    Base* ptrB = &c2;                   // Output: NICHTS (nothing)
    cout<<"-----------------------------------------"<<endl;

    delete ptrB;


}

int main() {
    test();
    return 0;
}
