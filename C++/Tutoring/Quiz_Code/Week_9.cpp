#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {
        cout << "Person Constructor: Name = " << name << ", Age = " << age << endl;
    }
    virtual ~Person() {
        cout << "Person Destructor: Name = " << name << endl;
    }

    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
    int studentID;

public:
    Student(string name, int age, int studentID)
        : Person(name, age), studentID(studentID) {
        cout << "Student Constructor: ID = " << studentID << endl;
    }

    ~Student() {
        cout << "Student Destructor: ID = " << studentID << endl;
    }

    void display() override {
        cout << "Student Name: " << name << ", Age: " << age << ", ID: " << studentID << endl;
    }

    // Overloading operator+
    Student operator+(Student& other) {
        return Student(this->name + " & " + other.name, (this->age + other.age) / 2, this->studentID + other.studentID);
    }
};










class Teacher : public Person {
    string subject;

public:
    Teacher(string name, int age, string subject)
        : Person(name, age), subject(subject) {
        cout << "Teacher Constructor: Subject = " << subject << endl;
    }

    ~Teacher() {
        cout << "Teacher Destructor: Subject = " << subject << endl;
    }

    void display() override {
        cout << "Teacher Name: " << name << ", Age: " << age << ", Subject: " << subject << endl;
    }
};


int main() {
    // Using raw pointers and inheritance
    Person* student = new Student("Alice", 20, 1234);
    Person* teacher = new Teacher("Mr. Smith", 45, "Mathematics");

    student->display();
    teacher->display();

    delete student;
    delete teacher;

    // Demonstrating polymorphism
    Person* person = new Student("Bob", 22, 5678);
    person->display();
    delete person;

    // Using operator overloading
    Student s1("Charlie", 19, 1111);
    Student s2("Diana", 21, 2222);
    Student s3 = s1 + s2;
    s3.display();

    return 0;
}