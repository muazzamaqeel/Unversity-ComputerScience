#include <iostream>
using namespace std;


///Classes and Objects
class Car {
public:
    string brand;
    void honk() {
        cout << "Beep beep!" << endl;
    }
};

int main() {
    Car myCar;
    myCar.brand = "Toyota1";
    cout << myCar.brand << endl;
    myCar.honk();

    cout << "/////////////////////////////////////////////" << endl;

    Car myCar2;
    myCar2.brand = "Toyota2";
    cout << myCar2.brand << endl;
    myCar2.honk();



    return 0;
}


///Constructor
/*
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    // Constructor
    Car(string b) {
        brand = b;
    }
};

int main() {
    Car myCar("Toyota");
    cout << myCar.brand << endl;
    return 0;
}
*/



///Destructor
/*
#include <iostream>
using namespace std;

class Car {
public:
    Car() {
        cout << "Car is being created" << endl;
    }
    // Destructor
    ~Car() {
        cout << "Car is being destroyed" << endl;
    }
};

int main() {
    Car myCar;
    return 0;
}
*/



///Inheritance

/*
#include <iostream>
using namespace std;

// Base class
class Vehicle {
public:
    string brand = "Ford";
    void honk() {
        cout << "Beep, Beep!" << endl;
    }
};

// Derived class
class Car: public Vehicle {
public:
    string model = "Mustang";
};

int main() {
    Car myCar;
    myCar.honk();
    cout << myCar.brand << " " << myCar.model << endl;
    return 0;
}
*/



///Polymorphism
/*
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void animalSound() {
        cout << "The animal makes a sound" << endl;
    }
};

class Cat : public Animal {
public:
    void animalSound() override {
        cout << "The cat says: wee wee" << endl;
    }
};

class Dog : public Animal {
public:
    void animalSound() override {
        cout << "The dog says: bark bark" << endl;
    }
};

int main() {
    Animal myAnimal;
    Cat myCat;
    Dog myDog;

    myAnimal.animalSound();
    myCat.animalSound();
    myDog.animalSound();
    return 0;
}
*/