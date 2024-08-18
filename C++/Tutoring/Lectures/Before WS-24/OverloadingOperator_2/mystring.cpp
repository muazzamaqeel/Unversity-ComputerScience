#include "mystring.h"
#include <cstring> // for strlen, strcpy, etc.

namespace stringexercise {

    // Default constructor
    mystring::mystring() : sequence(nullptr), occupied(0), capacity(0) {}

    // Constructor from C-string
    mystring::mystring(const char str[]) {
        occupied = strlen(str);
        capacity = occupied + 1;
        sequence = new char[capacity];
        strcpy(sequence, str);
    }

    // Copy constructor
    mystring::mystring(const mystring& source) {
        occupied = source.occupied;
        capacity = source.capacity;
        sequence = new char[capacity];
        strcpy(sequence, source.sequence);
    }

    // Destructor
    mystring::~mystring() {
        delete[] sequence;
    }
    // Assignment operator
    mystring& mystring::operator=(const mystring& source) {
        if (this == &source) return *this;

        char* new_sequence = new char[source.capacity];
        delete[] sequence;
        sequence = new_sequence;
        strcpy(sequence, source.sequence);
        occupied = source.occupied;
        capacity = source.capacity;
        return *this;
    }
    // Index operator
    char& mystring::operator[](size_t position) {
        if (position >= occupied) throw std::out_of_range("Index out of bounds");
        return sequence[position];
    }

    const char& mystring::operator[](size_t position) const {
        if (position >= occupied) throw std::out_of_range("Index out of bounds");
        return sequence[position];
    }

    // Concatenation and addition operators
    mystring& mystring::operator+=(const mystring& addend) {
        size_t new_length = occupied + addend.occupied;
        if (new_length >= capacity) {
            capacity = new_length + 1;
            char* new_sequence = new char[capacity];
            strcpy(new_sequence, sequence);
            delete[] sequence;
            sequence = new_sequence;
        }
        strcat(sequence, addend.sequence);
        occupied = new_length;
        return *this;
    }
    std::ostream& operator<<(std::ostream& outs, const mystring& source) {
        outs << source.sequence;
        return outs;
    }

    std::istream& operator>>(std::istream& ins, mystring& target) {
        char buffer[1000];
        ins.getline(buffer, 1000);
        target = buffer;
        return ins;
    }
}
