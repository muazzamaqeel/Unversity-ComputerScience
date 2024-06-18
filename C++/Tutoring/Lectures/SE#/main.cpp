#include <iostream>
#include <vector>

// Abstract base class component
class component {
public:
    virtual void abstract() = 0;
    virtual ~component() = default;
    virtual int getPrice() const = 0;
};

// Composite class Computer
class Composite : public component {
private:
    std::vector<component*> components;
public:
    Composite() {
        std::cout << "Creating Computer" << std::endl;
    }

    ~Composite() {
        std::cout << "Destroying Computer" << std::endl;
        for (auto comp : components) {
            delete comp;
        }
    }

    void abstract() override {
        std::cout << "Computer abstract function implementation" << std::endl;
    }

    int getPrice() const override {
        int total = 0;
        for (const auto& comp : components) {
            total += comp->getPrice();
        }
        return total;
    }

    void addComponent(component* comp)  {
        components.push_back(comp);
    }
};

// Leaf classes
class Motherboard : public component {
public:
    Motherboard() {
        price = 100;
        std::cout << "Creating Motherboard" << std::endl;
    }

    void abstract() override {
        std::cout << "Motherboard abstract function implementation" << std::endl;
    }

    int getPrice() const override {
        return price;
    }

private:
    int price;
};

class Processor : public component {
public:
    Processor() {
        price = 200;
        std::cout << "Creating Processor" << std::endl;
    }

    void abstract() override {
        std::cout << "Processor abstract function implementation" << std::endl;
    }

    int getPrice() const override {
        return price;
    }

private:
    int price;
};

class HardDisk : public component {
public:
    HardDisk() {
        price = 150;
        std::cout << "Creating HardDisk" << std::endl;
    }

    void abstract() override {
        std::cout << "HardDisk abstract function implementation" << std::endl;
    }

    int getPrice() const override {
        return price;
    }

private:
    int price;
};

class Peripheral_Devices : public component {
public:
    Peripheral_Devices() {
        price = 50;
        std::cout << "Creating Peripheral_Devices" << std::endl;
    }

    void abstract() override {
        std::cout << "Peripheral_Devices abstract function implementation" << std::endl;
    }

    int getPrice() const override {
        return price;
    }

private:
    int price;
};

int main() {
    Composite Composite;

    component* motherboard = new Motherboard();
    component* processor = new Processor();
    component* hardDisk = new HardDisk();
    component* peripheralDevices = new Peripheral_Devices();

    Composite.addComponent(motherboard);
    Composite.addComponent(processor);
    Composite.addComponent(hardDisk);
    Composite.addComponent(peripheralDevices);

    int totalPrice = Composite.getPrice();
    std::cout << "Total Price: $" << totalPrice << std::endl;

    return 0;
}
