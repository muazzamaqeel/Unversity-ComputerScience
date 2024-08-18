#include <iostream>
#include <vector>
#include <algorithm>

class Multiplier {
private:
    int num;
public:
    Multiplier(int n) : num{n} {}

    int operator()(int n) const {
        return num * n;
    }
};

int main() {
    std::vector<int> vec {1, 2, 3, 4};
    Multiplier mult(10);
    std::transform(vec.begin(), vec.end(), vec.begin(), mult);

    for (int val : vec) {
        std::cout << val << " ";
    }

    return 0;
}
