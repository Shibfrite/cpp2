#include <vector>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found" << std::endl;
    }

    try {
        easyfind(v, 99);
    } catch (std::exception& e) {
        std::cout << "Not found" << std::endl;
    }

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    try {
        std::list<int>::iterator it = easyfind(l, 10);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "Not found" << std::endl;
    }
}
