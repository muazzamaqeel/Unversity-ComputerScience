#include <iostream>
#include <vector>
using namespace std;


//Abstract Class
//We can't make an object from this class
class Vehicle {
public:
    string name;
    Vehicle(const std::string& name) : name(name) {}
    //Virtual Function is always = 0
    virtual double getFuelEfficiency()  = 0;
    friend ostream& operator<<(ostream& os,Vehicle& vehicle){
        os << "Vehicle Name: " << vehicle.name<<"\n"
           << "Fuel Efficiency: " << vehicle.getFuelEfficiency() << "km/l"<<endl;
           return os;
    }
    virtual ~Vehicle(){
        cout <<"Destructor of Vehicle has been called"<<endl;
    }
};
class Car : public Vehicle{
public:
    double engineSize;
    double weight;

    Car(string name, double engineSize, double weight):Vehicle(name),engineSize(engineSize),weight(weight){}

    double getFuelEfficiency() override {
        return 100.0 / (engineSize * (weight / 1000.0));
    }

};
class Bike : public Vehicle{
public:
    double engineCC;

    Bike(string name, double engineCC): Vehicle(name), engineCC(engineCC) {}

    double getFuelEfficiency() override {
        double FuelEfficiency;
        FuelEfficiency = 200/engineCC;
        return FuelEfficiency;

    }

};


int main() {

    //Vehicle*v1=new Car("Mazda",2.0, 1500.0);

    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Mazda",2.0, 1500.0));
    vehicles.push_back(new Bike("Motorbike", 150));

    for(int i = 0; i < vehicles.size(); i++){
        cout<<*vehicles[i];
    }
    for(int i = 0; i < vehicles.size(); i++) {
        delete vehicles[i];
    }

}
