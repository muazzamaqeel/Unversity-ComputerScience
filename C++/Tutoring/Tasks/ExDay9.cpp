### Wrapper Class
Theory Question:
1. Explain the purpose of a wrapper class in C++ and provide a scenario where it might be particularly useful.
   
Code-based Question:
2. Write a wrapper class for a simple integer value that includes methods for incrementing and decrementing the value.

Code-fix Question:
3. The following code is supposed to wrap an integer and provide a method to double its value, but it contains errors. Identify and fix the errors.
   ```cpp
   class IntWrapper {
   public:
       IntWrapper(int val) : value(val) {}
       void doubleValue() { value = value * 2 }
       int getValue() const { return value; }
   private:
       int value;
   };

   int main() {
       IntWrapper num(5);
       num.doubleValue();
       std::cout << num.getValue() << std::endl;
       return 0;
   }
   ```

### Virtual Destructors
Theory Question:
1. What is a virtual destructor in C++, and why is it important in the context of inheritance and polymorphism?

Code-based Question:
2. Write a base class with a virtual destructor and a derived class that overrides the destructor. Demonstrate how deleting a derived class object through a base class pointer invokes the correct destructor.

Code-fix Question:

3. The following code is intended to use virtual destructors but has a mistake. Identify and correct the error.
   class Base {
   public:
       ~Base() { std::cout << "Base destructor" << std::endl; }
   };

   class Derived : public Base {
   public:
       ~Derived() { std::cout << "Derived destructor" << std::endl; }
   };

   int main() {
       Base* obj = new Derived();
       delete obj;
       return 0;
   }
   ```

### Functors
Theory Question:
1. What is a functor in C++? How does it differ from a regular function or a lambda function?

Code-based Question:
2. Implement a functor that multiplies two numbers and demonstrate its usage in a `std::vector` algorithm.

Code-fix Question:
3. The following code attempts to use a functor but has a logical error. Identify and fix it.
   #include <iostream>
   #include <vector>
   #include <algorithm>

   class Adder {
   public:
       int operator()(int a, int b) { return a + b; }
   };

   int main() {
       std::vector<int> numbers = {1, 2, 3, 4, 5};
       Adder add;
       int sum = std::accumulate(numbers.begin(), numbers.end(), 0, add);
       std::cout << "Sum: " << sum << std::endl;
       return 0;
   }
   ```

### Binders
Theory Question:
1. What is the purpose of binders in C++? Provide an example of how `std::bind` can be used to bind arguments to a function.

Code-based Question:
2. Use `std::bind` to create a function that always multiplies a number by 10, and apply this function to each element of a `std::vector` using `std::for_each`.

Code-fix Question:
3. The following code tries to use `std::bind` but contains an error. Identify and fix it.
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>
   #include <functional>

   int multiply(int a, int b) {
       return a * b;
   }

   int main() {
       std::vector<int> numbers = {1, 2, 3, 4, 5};
       auto multiply_by_10 = std::bind(multiply, std::placeholders::_1, 10);
       std::for_each(numbers.begin(), numbers.end(), multiply_by_10);
       for (int num : numbers) {
           std::cout << num << " ";
       }
       std::cout << std::endl;
       return 0;
   }
   ```

### C++ Algorithms in STL
Theory Question:
1. Describe the role of algorithms in the C++ Standard Library (STL). Give an example of how `std::sort` can be used with a custom comparator.

Code-based Question:
2. Write a C++ program that uses `std::find_if` to locate the first even number in a `std::vector` of integers.

Code-fix Question:
3. The following code is meant to sort a `std::vector` of integers in descending order but contains an error. Identify and correct it.
   ```cpp
   #include <iostream>
   #include <vector>
   #include <algorithm>

   bool descending(int a, int b) {
       return a > b;
   }

   int main() {
       std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
       std::sort(numbers.begin(), numbers.end(), descending);
       for (int num : numbers) {
           std::cout << num << " ";
       }
       std::cout << std::endl;
       return 0;
   }
   ```

### Iterators
Theory Question:
1. What are iterators in C++ and what are the different types of iterators available in the STL? Provide an example of how a random access iterator is used.

Code-based Question:
2. Write a C++ program that uses a reverse iterator to print the elements of a `std::vector` in reverse order.

Code-fix Question:
3. The following code tries to use an iterator to iterate over a `std::list` but contains an error. Identify and fix the error.
   ```cpp
   #include <iostream>
   #include <list>

   int main() {
       std::list<int> numbers = {1, 2, 3, 4, 5};
       std::list<int>::iterator it;
       for (it = numbers.begin(); it != numbers.end(); ++it) {
           std::cout << *it << std::endl;
       }
       return 0;
   }