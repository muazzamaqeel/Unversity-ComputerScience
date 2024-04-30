#include <iostream>
#include <unordered_map>
#include "map"
#include "set"
using namespace std;

int main() {
    cout << "-------------------map-----------------------" << endl;
    map<int, string> data;
    data[1] = "Muazzam";
    data[3] = "Bin";
    data[2] = "Aqeel";
    map<int, string>::iterator it;
    for (it = data.begin(); it != data.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    cout << "-------------------multimap-----------------------" << endl;
    multimap<int, string> a;
    a.insert({1, "Aqeel"});
    a.insert({1, "Muazzam"});
    a.insert({2, "Bin"});
    for (auto it1 = a.begin(); it1 != a.end(); ++it1) {
        cout << it1->first << " " << it1->second << endl;
    }

    cout << "-------------------set-----------------------" << endl;
    set<int> set1;
    set1.insert(1);
    set1.insert(1);
    set<int>::iterator set_it;
    for (set_it = set1.begin(); set_it != set1.end(); ++set_it) {
        cout << *set_it << endl;
    }


    cout << "-------------------multiset-----------------------" << endl;
    // std::multiset can only store elements of a single data type,
    // as specified by its template parameter
    // However, you can use a class to add two parameters
    multiset<int> multiset;
    multiset.insert(10);
    multiset.insert(10);
    multiset.insert(10);
    set<int>::iterator multiset_it;
    for (multiset_it = multiset.begin(); multiset_it != multiset.end(); ++multiset_it) {
        cout << *multiset_it << endl;
    }

    cout << "-------------------unordered_map-----------------------" << endl;
    unordered_map<int, string> um_data;
    um_data[1] = "THU";
    um_data[3] = "CTS";
    um_data[2] = "C++";
    unordered_map<int, string>::iterator um_it;
    for (um_it = um_data.begin(); um_it != um_data.end(); ++um_it) {
        cout << um_it->first << " " << um_it->second << endl;
    }



}





