#include <iostream>
using namespace std;

class Resource {
public:
    Resource() { cout << "Resource "; }
    Resource(const Resource& r) { cout << "copyResource "; }
	void function() { cout << "function "; }
    virtual ~Resource() { cout << "~Resource "; }
};
class Base {
private:
    Resource res;
public:
    Base() { cout << "Base "; }
    Base(Base& b) : res(b.res) { cout << "copyBase "; }
    virtual void action() { cout << "actionBase "; }
    Resource getData() { return res; }
    virtual ~Base() { cout << "~Base "; }
};
class Intermediate : public Base {
public:
    Intermediate() { cout << "Intermediate "; }
    Intermediate(Intermediate& i) { cout << "copyIntermediate "; }
    void action() { cout << "actionIntermediate "; }
    ~Intermediate() { cout << "~Intermediate "; }
};
class Derived : public Intermediate {
private:
    Resource* ptrRes = new Resource();
	Resource* ptrRes2 = nullptr;
	Resource objRes;
public:
    Derived() {cout << "Derived ";}
    Derived(Derived& d) : Intermediate(d) {cout << "copyDerived ";}
    void action() { cout << "actionDerived "; }
    ~Derived() {cout << "~Derived ";delete ptrRes;}
};
void process(Base b) {b.action();}
void process(Base* b) { b->action(); b->getData().function();}





void test() {
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "1" << endl;                        // Step 1: Print "1"
    cout << "-" << endl;                        // Step 1: Print "1"

    Derived d1;
    cout << "-" << endl;                        // Step 1: Print "1"
                                                // Step 2: Create Derived object d1
    cout << "2" << endl;                        // Step 3: Print "2"
    cout << "-" << endl;                        // Step 1: Print "1"

    Derived d2 = d1;                            // Step 4: Copy construct Derived object d2 from d1
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "3" << endl;                        // Step 5: Print "3"
    cout << "-" << endl;                        // Step 1: Print "1"

    Base* ptrB = new Derived();
    cout << "-" << endl;                        // Step 1: Print "1"
                                                // Step 6: Dynamically allocate Derived object and assign to Base pointer ptrB
    cout << "4" << endl;                        // Step 7: Print "4"
    cout << "-" << endl;                        // Step 1: Print "1"

    process(d1);                                // Step 8: Call process function with Derived reference d1
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "5" << endl;                        // Step 9: Print "5"
    cout << "-" << endl;                        // Step 1: Print "1"

    process(ptrB);                              // Step 10: Call process function with Base pointer ptrB
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "6" << endl;                        // Step 11: Print "6"
    cout << "-" << endl;                        // Step 1: Print "1"

    delete ptrB;                                // Step 12: Delete dynamically allocated Derived object pointed to by ptrB
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "7" << endl;                        // Step 13: Print "7"
    cout << "-" << endl;                        // Step 1: Print "1"

    Intermediate* ptrI = new Intermediate(d2);  // Step 14: Dynamically allocate Intermediate object using d2 and assign to ptrI
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "8" << endl;                        // Step 15: Print "8"
    cout << "-" << endl;                        // Step 1: Print "1"

    ptrI->action();                             // Step 16: Call action method on Intermediate object pointed to by ptrI
    cout << "-" << endl;                        // Step 1: Print "1"
    cout << "9" << endl;                        // Step 17: Print "9"
    cout << "-" << endl;                        // Step 1: Print "1"

    delete ptrI;                                // Step 18: Delete dynamically allocated Intermediate object pointed to by ptrI
    cout << "10" << endl;                       // Step 19: Print "10"
}


int main() {
    test();
    return 0;
}
