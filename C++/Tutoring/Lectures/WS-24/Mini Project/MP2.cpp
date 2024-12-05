#include <iostream>
#include <vector>
#include <iomanip> // For formatting output

// Base class Vehicle
class Vehicle {
protected:
    std::string name;
public:
    Vehicle(const std::string& name) : name(name) {}
    virtual ~Vehicle() {} // Virtual destructor for proper cleanup in derived classes

    // Pure virtual function to calculate fuel efficiency
    virtual double getFuelEfficiency() const = 0;

    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
        os << "Vehicle Name: " << vehicle.name << "\n"
           << "Fuel Efficiency: " << std::fixed << std::setprecision(2)
           << vehicle.getFuelEfficiency() << " km/l";
        return os;
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    double engineSize; // in liters
    double weight;     // in kilograms
public:
    Car(const std::string& name, double engineSize, double weight)
        : Vehicle(name), engineSize(engineSize), weight(weight) {}

    double getFuelEfficiency() const override {
        return 100.0 / (engineSize * (weight / 1000.0));
    }
};

// Derived class Bike
class Bike : public Vehicle {
private:
    double engineCC; // in cubic centimeters (CC)
public:
    Bike(const std::string& name, double engineCC)
        : Vehicle(name), engineCC(engineCC) {}

    double getFuelEfficiency() const override {
        return 200.0 / engineCC;
    }
};

int main() {
    // Create a vector to store pointers to Vehicle objects
    std::vector<Vehicle*> vehicles;

    // Dynamically allocate Car and Bike objects
    vehicles.push_back(new Car("Sedan", 2.0, 1500)); // Car with engine size 2.0L and weight 1500kg
    vehicles.push_back(new Bike("Motorbike", 150));  // Bike with engine capacity 150CC

    // Traditional for loop for displaying fuel efficiencies
    for (int i = 0; i < vehicles.size(); i++) {
        std::cout << *vehicles[i] << "\n\n";
    }

    // Proper memory management: delete dynamically allocated objects
    for (int i = 0; i < vehicles.size(); i++) {
        delete vehicles[i];
    }

    return 0;
}
