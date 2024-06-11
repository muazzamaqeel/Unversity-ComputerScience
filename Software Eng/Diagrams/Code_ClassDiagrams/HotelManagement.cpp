#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Forward declarations
class Room;
class Invoice;
class Service;
class PaymentMethod;
class RoomCategory;
class Customer;

// Class: RoomCategory
class RoomCategory {
public:
    RoomCategory(const std::string& type, double price) 
        : type(type), price(price) {}

    std::string getType() const { return type; }
    double getPrice() const { return price; }

private:
    std::string type;
    double price;
};

// Class: Room
class Room {
public:
    Room(int roomNo, std::shared_ptr<RoomCategory> category)
        : roomNo(roomNo), status("Available"), category(category) {}

    int getRoomNo() const { return roomNo; }
    std::string getStatus() const { return status; }
    std::shared_ptr<RoomCategory> getCategory() const { return category; }

    void reserve() { status = "Reserved"; }
    void release() { status = "Available"; }

private:
    int roomNo;
    std::string status;
    std::shared_ptr<RoomCategory> category;
};

// Class: Service
class Service {
public:
    Service(const std::string& name, double price)
        : name(name), price(price) {}

    std::string getName() const { return name; }
    double getPrice() const { return price; }

private:
    std::string name;
    double price;
};

// Class: Invoice
class Invoice {
public:
    Invoice(int invoiceNo, std::shared_ptr<Customer> customer)
        : invoiceNo(invoiceNo), amount(0), customer(customer) {}

    int getInvoiceNo() const { return invoiceNo; }
    double getAmount() const { return amount; }
    std::shared_ptr<Customer> getCustomer() const { return customer; }

    void addService(std::shared_ptr<Service> service) {
        services.push_back(service);
        amount += service->getPrice();
    }

    void addRoomCharge(double roomCharge) {
        amount += roomCharge;
    }

private:
    int invoiceNo;
    double amount;
    std::shared_ptr<Customer> customer;
    std::vector<std::shared_ptr<Service>> services;
};

// Class: PaymentMethod
class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
};

// Class: CashPayment
class CashPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        // Implementation for cash payment
        std::cout << "Paid " << amount << " with cash." << std::endl;
    }
};

// Class: CreditCardPayment
class CreditCardPayment : public PaymentMethod {
public:
    CreditCardPayment(const std::string& cardNumber)
        : cardNumber(cardNumber) {}

    void pay(double amount) override {
        // Implementation for credit card payment
        std::cout << "Paid " << amount << " with credit card number " << cardNumber << std::endl;
    }

private:
    std::string cardNumber;
};

// Class: Person
class Person {
public:
    Person(int id, const std::string& name, const std::string& phoneNo) 
        : id(id), name(name), phoneNo(phoneNo) {}
    virtual ~Person() {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getPhoneNo() const { return phoneNo; }

private:
    int id;
    std::string name;
    std::string phoneNo;
};

// Class: Customer
class Customer : public Person, public std::enable_shared_from_this<Customer> {
public:
    Customer(int id, const std::string& name, const std::string& phoneNo, const std::string& address)
        : Person(id, name, phoneNo), address(address) {}

    void requestBooking(std::shared_ptr<Room> room) {
        room->reserve();
        currentRoom = room;
        std::cout << "Room " << room->getRoomNo() << " reserved." << std::endl;
    }

    void useService(std::shared_ptr<Service> service) {
        servicesUsed.push_back(service);
    }

    void checkOut() {
        if (currentRoom) {
            currentRoom->release();
            currentRoom.reset();
        }
    }

    std::shared_ptr<Invoice> generateInvoice(int invoiceNo) {
        auto invoice = std::make_shared<Invoice>(invoiceNo, shared_from_this());
        if (currentRoom) {
            invoice->addRoomCharge(currentRoom->getCategory()->getPrice());
        }
        for (const auto& service : servicesUsed) {
            invoice->addService(service);
        }
        return invoice;
    }

private:
    std::string address;
    std::shared_ptr<Room> currentRoom;
    std::vector<std::shared_ptr<Service>> servicesUsed;
};

int main() {
    // Create some room categories
    auto standardCategory = std::make_shared<RoomCategory>("Standard", 100.0);
    auto deluxeCategory = std::make_shared<RoomCategory>("Deluxe", 200.0);

    // Create some rooms
    auto room101 = std::make_shared<Room>(101, standardCategory);
    auto room102 = std::make_shared<Room>(102, deluxeCategory);

    // Create some services
    auto laundryService = std::make_shared<Service>("Laundry", 20.0);
    auto drinkService = std::make_shared<Service>("Drink", 5.0);

    // Create a customer
    auto customer = std::make_shared<Customer>(1, "John Doe", "123456789", "123 Main St");

    // Request booking and use services
    customer->requestBooking(room101);
    customer->useService(laundryService);
    customer->useService(drinkService);

    // Generate invoice
    auto invoice = customer->generateInvoice(1);
    std::cout << "Invoice generated with total amount: " << invoice->getAmount() << std::endl;

    // Customer pays with cash
    CashPayment cashPayment;
    cashPayment.pay(invoice->getAmount());

    return 0;
}
