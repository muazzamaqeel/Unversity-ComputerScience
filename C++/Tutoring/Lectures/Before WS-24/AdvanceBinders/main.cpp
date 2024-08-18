#include <iostream>
using namespace std;

class Part {
public:
    Part() { cout << " Part"; }
    Part(Part& b) { cout << " copyPart"; }
    ~Part() { cout << " ~Part"; }
};

class Top {
public:
    Top() { cout << " cTop"; }
    Top(Top& a) { cout << " copyTop"; }
      ~Top() { cout << " ~Top"; }
};

class Middle : public Top {
protected:
    Part* p1;
    Part p2;
public:
    Middle() { cout << " cMiddle"; }
    Middle(Middle& m) { cout << " copyMiddle"; }
     ~Middle() { cout << " ~Middle"; }
    void useTop(Top t) { cout << " usingTop"; }
};

class Bottom : public Middle {
public:
    Bottom() { cout << " cBottom"; }
    Bottom(Bottom& b) { cout << " copyBottom"; }
    ~Bottom() { cout << " ~Bottom"; }
};

void test() {

    Middle* t1 = new Bottom();
    cout << endl;
    delete t1;
    cout << endl;
}

int main() {
    test();
    cin.sync(); cin.get();
}
