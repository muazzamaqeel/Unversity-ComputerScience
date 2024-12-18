#include <iostream>
#include <memory> // Required for smart pointers

void uniquePointerExample() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(10);
    std::cout << "[unique_ptr] Value: " << *uniquePtr << std::endl;

    // Memory will be freed automatically when uniquePtr goes out of scope
} // uniquePtr is deleted here

void sharedPointerExample() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(20);
    std::cout << "\n[shared_ptr] Value: " << *sharedPtr1 << std::endl;

    {
        std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Shared ownership
        std::cout << "[shared_ptr] Ownership count inside block: " << sharedPtr1.use_count() << std::endl;
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
        std::cout << "[weak_ptr] The shared pointer has expired!" << std::endl;
    } else {
        std::cout << "[weak_ptr] This should not happen!" << std::endl;
    }
}

int main() {
    std::cout << "=== unique_ptr Example ===" << std::endl;
    uniquePointerExample();

    std::cout << "\n=== shared_ptr Example ===" << std::endl;
    sharedPointerExample();

    std::cout << "\n=== weak_ptr Example ===" << std::endl;
    weakPointerExample();

    return 0;
}

/*

=== unique_ptr Example ===
[unique_ptr] Value: 10

=== shared_ptr Example ===
[shared_ptr] Value: 20
[shared_ptr] Ownership count inside block: 2
[shared_ptr] Ownership count after block: 1

=== weak_ptr Example ===
[weak_ptr] Shared pointer value: 30
[weak_ptr] Locked value: 30
[weak_ptr] The shared pointer has expired!


*/

//Advance Example
void sharedPointerExample() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(100); // Shared ownership
    std::cout << "Initial use count: " << sharedPtr1.use_count() << std::endl;

    {
        std::shared_ptr<int> sharedPtr2 = sharedPtr1; // Second shared_ptr
        std::shared_ptr<int> sharedPtr3 = sharedPtr1; // Third shared_ptr

        std::cout << "Use count after creating sharedPtr2 and sharedPtr3: " 
                  << sharedPtr1.use_count() << std::endl;

        // Check values
        std::cout << "sharedPtr1 value: " << *sharedPtr1 << std::endl;
        std::cout << "sharedPtr2 value: " << *sharedPtr2 << std::endl;
        std::cout << "sharedPtr3 value: " << *sharedPtr3 << std::endl;
    } // sharedPtr2 and sharedPtr3 go out of scope

    std::cout << "Use count after sharedPtr2 and sharedPtr3 are destroyed: " 
              << sharedPtr1.use_count() << std::endl;

    // Create a weak_ptr that observes sharedPtr1
    std::weak_ptr<int> weakPtr = sharedPtr1;

    if (auto lockedPtr = weakPtr.lock()) { // Lock weak_ptr to access the resource
        std::cout << "Weak pointer is still valid. Value: " << *lockedPtr << std::endl;
    }

    // Reset the last shared_ptr
    sharedPtr1.reset();

    // Now weak_ptr is observing expired memory
    if (weakPtr.expired()) {
        std::cout << "Weak pointer expired after all shared_ptr objects were deleted!" << std::endl;
    }
}