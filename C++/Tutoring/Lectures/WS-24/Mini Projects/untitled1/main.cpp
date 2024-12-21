#include <iostream>
#include <map>
#include <vector>
#include <memory>
using namespace std;


void uniquePointerExample() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(10);
    std::cout << "[unique_ptr] Value: " << *uniquePtr << std::endl;
    cout<<uniquePtr;

    // Memory will be freed automatically when uniquePtr goes out of scope


} // uniquePtr is deleted here

void sharedPointerExample() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(20);
    std::cout << "\n[shared_ptr] Value: " << *sharedPtr1 << std::endl;

    std::shared_ptr<int> &sharedPtr3 =sharedPtr1;

    {
        std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Shared ownership
        std::cout << "[shared_ptr] Ownership count inside block: " << sharedPtr1.use_count() << std::endl;
        sharedPtr2.reset();

    } // sharedPtr2 goes out of scope, reducing ownership count

    std::cout << "[shared_ptr] Ownership count after block: " << sharedPtr1.use_count() << std::endl;
    // Memory is freed when the last shared_ptr is destroyed


} // sharedPtr1 is deleted here


void weakPointerExample() {
    std::weak_ptr<int> weakPtr;

    {
        std::shared_ptr<int> sharedPtr = std::make_shared<int>(30);
        weakPtr = sharedPtr; // weak_ptr observes sharedPtr

        std::cout << "\n[weak_ptr] Shared pointer value: " << *sharedPtr << std::endl;

        // Lock weak_ptr to access the shared object
        if (auto lockedPtr = weakPtr.lock()) {
            std::cout << "[weak_ptr] Locked value: " << *lockedPtr << std::endl;
        }
    } // sharedPtr is deleted here (ownership count becomes zero)

    // Now, weak_ptr observes expired memory
    if (weakPtr.expired()) {
        std::cout << "[weak_ptr] The shared pointer has not expired!" << std::endl;
    } else {
        std::cout << "[weak_ptr] This should not happen!" << std::endl;
    }
}

int main() {
    weakPointerExample();

}
