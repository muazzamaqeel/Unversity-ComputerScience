#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sPtr = std::make_shared<int>(30);
    std::weak_ptr<int> wPtr = sPtr;  // wPtr points to the same int as sPtr but does not increase reference count

    std::cout << "Original Shared Pointer: " << *sPtr << std::endl;
    std::cout << "Reference Count: " << sPtr.use_count() << std::endl;

    // Check if the object is still around and if so, use it
    if (std::shared_ptr lockedPtr = wPtr.lock()) {
        std::cout << "Weak Pointer (locked): " << *lockedPtr << std::endl;
    } else {
        std::cout << "No managed object" << std::endl;
    }

    // Clearing the original shared pointer
    sPtr.reset();

    if (wPtr.expired()) {
        std::cout << "Weak pointer is expired after shared pointer reset." << std::endl;
    }

    return 0;
}
