#include <iostream>

class SimpleC {
private:
    int value;
public:
    // Constructor
    SimpleC(int val) : value(val) {}

    // Getter
    int getValue() const {
        return value;
    }

    // Setter
    void setValue(int val) {
        value = val;
    }

    // Method to display the value
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    SimpleC wrappedInt(42); // Creating an object of IntWrapper with initial value 42
    wrappedInt.display(); // Display the value

    wrappedInt.setValue(100); // Set a new value
    wrappedInt.display(); // Display the updated value

    std::cout << "Retrieved value: " << wrappedInt.getValue() << std::endl; // Retrieve and display the value

    return 0;
}



/*
### Explanation:

1. *Class Definition:*
   - IntWrapper class encapsulates an integer value. It has a private member value to store the integer.
   - It provides a constructor to initialize the value, getter and setter methods to access and modify the value, and a display method to print the value.

2. *Main Function:*
   - An instance of IntWrapper is created with an initial value of 42.
   - The display method is called to print the value.
   - The setValue method is used to change the value to 100, and the display method is called again.
   - The getValue method is used to retrieve and print the value.

This simple example illustrates how you can wrap a primitive type in a class to provide additional functionality and encapsulation in C++.

*/




//Advance Example


#include <iostream>

// Temperature class
class Temperature {
private:
    double celsius;
public:
    Temperature(double temp) : celsius(temp) {}
    
    double getCelsius() const {
        return celsius;
    }

    void setCelsius(double temp) {
        celsius = temp;
    }

    double toFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    void display() const {
        std::cout << "Temperature: " << celsius << "°C" << std::endl;
    }
};

// Distance class
class Distance {
private:
    double meters;
public:
    Distance(double dist) : meters(dist) {}

    double getMeters() const {
        return meters;
    }

    void setMeters(double dist) {
        meters = dist;
    }

    double toKilometers() const {
        return meters / 1000.0;
    }

    void display() const {
        std::cout << "Distance: " << meters << " meters" << std::endl;
    }
};

// Weight class
class Weight {
private:
    double kilograms;
public:
    Weight(double wt) : kilograms(wt) {}

    double getKilograms() const {
        return kilograms;
    }

    void setKilograms(double wt) {
        kilograms = wt;
    }

    double toPounds() const {
        return kilograms * 2.20462;
    }

    void display() const {
        std::cout << "Weight: " << kilograms << " kg" << std::endl;
    }
};

// Wrapper class
class MeasurementWrapper {
private:
    Temperature temp;
    Distance dist;
    Weight weight;
public:
    MeasurementWrapper(double t, double d, double w)
        : temp(t), dist(d), weight(w) {}

    // Access and display functions for temperature
    void displayTemperature() const {
        temp.display();
    }

    double getTemperatureInFahrenheit() const {
        return temp.toFahrenheit();
    }

    // Access and display functions for distance
    void displayDistance() const {
        dist.display();
    }

    double getDistanceInKilometers() const {
        return dist.toKilometers();
    }

    // Access and display functions for weight
    void displayWeight() const {
        weight.display();
    }

    double getWeightInPounds() const {
        return weight.toPounds();
    }
};

int main() {
    // Create a MeasurementWrapper object
    MeasurementWrapper measurements(25.0, 1000.0, 70.0);

    // Display temperature
    measurements.displayTemperature();
    std::cout << "Temperature in Fahrenheit: " << measurements.getTemperatureInFahrenheit() << "°F" << std::endl;

    // Display distance
    measurements.displayDistance();
    std::cout << "Distance in Kilometers: " << measurements.getDistanceInKilometers() << " km" << std::endl;

    // Display weight
    measurements.displayWeight();
    std::cout << "Weight in Pounds: " << measurements.getWeightInPounds() << " lbs" << std::endl;

    return 0;
}





#include <iostream>
#include <vector>
#include <algorithm>

// Functor class
class Multiply {
public:
    int operator()(int a, int b) const {
        a=1;
        b=2;
        return a * b;
    }
};

int main() {
    Multiply obj;
    int result = obj(5, 3);
    std::cout << "Functor result:" << result << std::endl;

    auto lamda = [](int a, int b) {
        return a + b;
    };

    int sum = lamda(5, 3);
    std::cout << "Lambda function result: " << sum << std::endl;

    return 0;
}

