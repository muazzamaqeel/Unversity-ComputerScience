#include <iostream>
using namespace std;

class Part {
public:
    Part() { cout << " cPart\n"; }
    Part(const Part& a) { cout << " copyPart\n"; }
    ~Part() { cout << " ~Part"; }
};

class Base {
private:
    Part p;
public:
    Base() { cout << " cBase\n"; }
    Base(const Base& b) { cout << " copyBase\n"; }
    virtual ~Base() { cout << " ~Base"; }

    void method1(Base b) { cout << " m1Base\n"; }
};

class Child : public Base {
private:
    Part* ptrP;
public:
    Child() { cout << " cChild\n"; ptrP = 0; }
    Child(const Child& c) { cout << " copyChild\n"; ptrP = c.ptrP; }
    ~Child() { cout << " ~Child"; if (ptrP) delete ptrP; }

    void method1(Base b) { cout << " m1Child\n"; }
    void method1(Base* b) { cout << " m1_Child\n"; b->method1(*b); }
    void method2() { cout << " m2Child\n"; ptrP = new Part(); }
};

void test() {
    Child c1;
    Child c2 = c1;

    Base b1;

    Base* ptrB = &c2;
    ptrB->method1(c1);

    ptrB = new Child();
    static_cast<Child*>(ptrB)->method2();

    c1.method2();

    cout<<""<<endl;
    cout<<"----------------"<<endl;
    cout<<""<<endl;
    delete ptrB;
    cout<<""<<endl;
    cout<<"----------------"<<endl;
    cout<<""<<endl;

    Child* ptrC = &c1;
    ptrC->method1(&c2);


    cout<<""<<endl;
    cout<<"----------------"<<endl;
    cout<<""<<endl;
    delete ptrC;
    cout<<""<<endl;
    cout<<"----------------"<<endl;
    cout<<""<<endl;
    cout<<"----------------"<<endl;
    cout<<""<<endl;
}

int main() {
    test();
    return 0;
}
