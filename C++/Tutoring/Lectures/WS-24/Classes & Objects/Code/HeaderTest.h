//
// Created by muazz on 24/10/2024.
//

#ifndef CODE_HEADERTEST_H
#define CODE_HEADERTEST_H


class HeaderTest {
public:
    // Constructor
    HeaderTest() : value(0) {
    }

    // Setter
    void setValue(int val) {
        value = val;
    }

    // Getter
    int getValue() const {
        return value;
    }

private:
    int value; // Private member variable
};


#endif //CODE_HEADERTEST_H
