#include <iostream>
#include "iter.hpp"

template<typename T>
void print_const(const T& x) {
    std::cout << x << " ";
}

template<typename T>
void increment(T& x) {
    x++;
}

int main() {
    int ints[] = {1, 2, 3};
    const char chars[] = {'a', 'b', 'c'};
    double doubles[] = {1.1, 2.2, 3.3};

    iter(ints, 3, print_const<int>);
    std::cout << "\n";

    iter(chars, 3, print_const<char>);
    std::cout << "\n";

    iter(doubles, 3, print_const<double>);
    std::cout << "\n";

    iter(ints, 3, increment<int>);
    
    for (size_t i = 0; i < 3; i++) {
        std::cout << ints[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
