#include <iostream>
#include "Array.hpp"

int main() {
    // Test 1: Default Constructor
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    // Test 2: Size Constructor & Value Initialization
    Array<int> nums(5);
    std::cout << "Nums size: " << nums.size() << std::endl;
    std::cout << "Default val (should be 0): " << nums[0] << std::endl;

    // Test 3: Operator[] Assignment & Access
    nums[0] = 42;
    nums[1] = 10;
    std::cout << "Assigned val: " << nums[0] << std::endl;

    // Test 4: Out of Bounds Exception
    try {
        int x = nums[10];
        (void)x;
        std::cout << "ERROR: No exception thrown!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test 5: Copy Constructor (Deep Copy)
    Array<int> copy(nums);
    copy[0] = 99;
    std::cout << "Original after copy mod: " << nums[0] << " (Should be 42)" << std::endl;
    std::cout << "Copy value: " << copy[0] << " (Should be 99)" << std::endl;

    // Test 6: Assignment Operator (Deep Copy)
    Array<int> assigned(2);
    assigned = nums;
    assigned[1] = 77;
    std::cout << "Original after assign mod: " << nums[1] << " (Should be 10)" << std::endl;
    std::cout << "Assigned value: " << assigned[1] << " (Should be 77)" << std::endl;

    /* those tests create compilation error
    // Test 7: Self Assignment 
    nums = nums;
    std::cout << "Self assignment safe: " << nums[0] << std::endl;

    // Test 8: Const Correctness
    const Array<int> const_arr(3);
    try {
        const_arr[0] = 5; // Should fail compilation if uncommented, testing access only
        std::cout << "Const access: " << const_arr[0] << std::endl;
    } catch (...) {
        std::cout << "Const access failed" << std::endl;
    }
    */

    // Test 9: Different Types
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    std::cout << "String array: " << strings[0] << " " << strings[1] << std::endl;

    return 0;
}
