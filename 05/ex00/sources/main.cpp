#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    // Test valid bureaucrat
    try {
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
        ++bob;
        std::cout << bob << std::endl;
        --bob;
        std::cout << bob << std::endl;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test grade too high
    try {
        Bureaucrat alice("Alice", 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test grade too low
    try {
        Bureaucrat charlie("Charlie", 151);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test increment past limit
    try {
        Bureaucrat dave("Dave", 1);
        std::cout << dave << std::endl;
        ++dave;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // Test decrement past limit
    try {
        Bureaucrat eve("Eve", 150);
        std::cout << eve << std::endl;
        --eve;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
