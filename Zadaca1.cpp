#include <iostream>
#include <vector>

template<typename T>
bool palindrom(const std::vector<T>& v) {
    std::vector<T> reversed_v(v.rbegin(), v.rend());
    return std::equal(v.begin(), v.end(), reversed_v.begin());
}

int main() {
    std::vector<int> v1 = {1, 2, 3, 2, 1};
    std::vector<int> v2 = {1, 2, 3, 4, 5};
    std::vector<char> v3 = {'a', 'b', 'c', 'b', 'a'};
    std::vector<char> v4 = {'a', 'b', 'c', 'd', 'e'};

    std::cout << std::boolalpha << palindrom(v1) << '\n'; // true
    std::cout << std::boolalpha << palindrom(v2) << '\n'; // false
    std::cout << std::boolalpha << palindrom(v3) << '\n'; // true
    std::cout << std::boolalpha << palindrom(v4) << '\n'; // false

    return 0;
}
