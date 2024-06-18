#include <iostream>
#include <map>
#include <sstream>
#include <string>



//Get data from user and add in the app

int main() {

    // Create a map to store word counts
    std::map<int, std::string> data;

    // Prompt the user for input
    std::cout <<"Please tell me how many data elements you want to add"<<std::endl;
    int Number_of_Elements;
    std::cin >> Number_of_Elements;

    for (int i=0; i<Number_of_Elements; ++i){
    std::cout << "Enter your name: ";
    std::string name;
    std::cin >> name;
    data[i] = name;
    }

    //Print out the map

    std::map<int, std::string>::iterator loop_var;

    for (loop_var = data.begin(); loop_var != data.end(); ++loop_var) {
        std::cout << loop_var->second<<std::endl;
        std::cout << loop_var->first<<std::endl;

    }

}









