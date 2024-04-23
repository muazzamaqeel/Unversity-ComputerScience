#include <iostream>

class Base {
public:
    virtual void say() { std::cout << "Base class\n"; }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    void say() override { std::cout << "Derived class\n"; }
};

int main() {
    Base* b = new Base;
    Derived* d = new Derived;

    // Static cast for upcasting
    Base* b1 = static_cast<Base*>(d);  // Safe and correct

    // Static cast for downcasting: Unsafe and should be avoided if not sure
    Derived* d1 = static_cast<Derived*>(b);  // Compiles, but unsafe and wrong behavior if b is not a Derived

    // Dynamic cast for upcasting: Overkill, but correct
    Base* b2 = dynamic_cast<Base*>(d);  // Works but unnecessary

    // Dynamic cast for downcasting: Safe and correct
    Derived* d2 = dynamic_cast<Derived*>(b);  // Returns nullptr since b is not a Derived
    if (d2) {
        std::cout << "Dynamic cast successful\n";
    } else {
        std::cout << "Dynamic cast failed\n";
    }

    delete b;
    delete d;
    return 0;
}

/*
 *
- `Base* b` points to a `Base` object, and `Derived* d` points to a `Derived` object.
- `b` is safely upcasted to `Base* b1` using static casting because `Derived` can be treated as `Base`.
- `Derived* d1` is downcasted from `b`, but it's unsafe because `b` is not a `Derived` object. This can lead to errors.
- `Base* b2` is upcasted to `Base*` using dynamic casting, which is overkill but works correctly.
- `Derived* d2` is downcasted from `b` using dynamic casting, but since `b` is not pointing to a `Derived` object, it returns `nullptr`.
- Memory for `b` and `d` is deallocated using `delete` to prevent memory leaks.
 *
 */