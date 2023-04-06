#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main() {
    std::deque<int> d = {1, 2, 3, 4, 5};
    std::vector<int> v(d.rbegin(), d.rend());

    for (const auto& num : v) {
        std::cout << num << ' ';
    }

    return 0;
}
