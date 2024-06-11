#include <iostream>
#include <string>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    int year;

public:
    Book(const std::string& t, const std::string& a, int y)
         {
            title=t; 
            author=a; 
            year=y;
         }

    std::string toString() const {
        return title + " by " + author + " (" + std::to_string(year) + ")";
    }


    // Overload the == operator
    bool operator==(const Book& other) const {
        return (title == other.title) && (author == other.author) && (year == other.year);
    }

    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.toString();
        return os;
    }

};



int main() {
    Book book1("1984", "George Orwell", 1949);
    Book book2("Animal Farm", "George Orwell", 1945);
    Book book3("1984", "George Orwell", 1949);

    // Comparison using overloaded ==
    if (book1 == book3) {
        std::cout << "Books are equal" << std::endl;
    } else {
        std::cout << "Books are not equal" << std::endl;
    }

    // Printing using overloaded <<
    std::cout << book1 << std::endl;

    return 0;
}
