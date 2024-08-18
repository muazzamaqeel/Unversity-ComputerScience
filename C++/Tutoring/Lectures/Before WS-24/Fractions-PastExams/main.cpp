#include <iostream>
#include <stdexcept> // for std::invalid_argument
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function to reduce fractions
    void reduce() {
        int gcd = getGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    // Helper function to compute greatest common divisor
    int getGCD(int a, int b) const {
        if (b == 0) return a;
        return getGCD(b, a % b);
    }

public:
    // Constructor
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // Overloaded + operator
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overloaded * operator
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Overloaded == operator
    bool operator==(const Fraction& other) const {
        return (numerator == other.numerator && denominator == other.denominator);
    }

    // Friend function for outputting fraction
    friend ostream& operator<<(ostream& os, const Fraction& frac);
};

ostream& operator<<(ostream& os, const Fraction& frac) {
    os << frac.numerator << "/" << frac.denominator;
    return os;
}

int main() {
    try {
        Fraction frac1(1, 2); // 1/2
        Fraction frac2(3, 4); // 3/4

        Fraction resultAdd = frac1 + frac2;
        Fraction resultMul = frac1 * frac2;

        cout << frac1 << " + " << frac2 << " = " << resultAdd << endl; // Expected: 1/2 + 3/4 = 5/4
        cout << frac1 << " * " << frac2 << " = " << resultMul << endl; // Expected: 1/2 * 3/4 = 3/8

        // Testing commutative property
        cout << frac2 << " + " << frac1 << " = " << (frac2 + frac1) << endl; // Expected: 3/4 + 1/2 = 5/4
        cout << frac2 << " * " << frac1 << " = " << (frac2 * frac1) << endl; // Expected: 3/4 * 1/2 = 3/8

        // Equality check
        Fraction frac3(2, 4); // 2/4 should reduce to 1/2
        cout << frac1 << " == " << frac3 << " is " << (frac1 == frac3 ? "true" : "false") << endl; // Expected: true

    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
