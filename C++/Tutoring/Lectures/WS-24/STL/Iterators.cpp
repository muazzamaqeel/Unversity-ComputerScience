#include <iostream>
#include <map>

int main() {
    // Create a std::map
    std::map<int, std::string> myMap = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Cherry"}
    };

    //  Attempting to use a traditional for loop with index-based access (won't work)
    //  for (size_t i = 0; i < myMap.size(); ++i) {
    //  std::cout << myMap[i] << " ";  // Error: std::map does not support operator[]
    //  }


    std::map<int, std::string>::iterator it;
    std::cout << "Using an iterator to traverse std::map:" << std::endl;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    // Declare the variable for the range-based for loop
    std::pair<const int, std::string> pair;
    std::cout << "\nUsing a range-based for loop to traverse std::map:" << std::endl;
    for (const auto& pair : myMap) {  // Alternative: Declare `pair` within the loop for simplicity
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }

    return 0;
}
