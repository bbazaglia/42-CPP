#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    std::cout << "Test 1: Construction with no parameter" << std::endl;
    Array<int> arr1;  // Empty array
    std::cout << "arr1 size: " << arr1.size() << std::endl;  // Should output 0

    try {
        std::cout << "Trying to access arr1 (empty array): ";
        std::cout << arr1[0] << std::endl;  // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;  // Should print "Index out of bounds"
    }
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 2: Construction with a specified number of elements (5 elements)" << std::endl;
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;  // Should output 5

    // Set some values
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        arr2[i] = i + 1;  // Set values 1, 2, 3, 4, 5
    }

    // Print arr2 using the subscript operator
    std::cout << "arr2 elements: ";
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "Test 3: Test copy constructor" << std::endl;
    Array<int> arr3 = arr2;  // Copy constructor
    std::cout << "arr3 size: " << arr3.size() << std::endl;  // Should output 5
    std::cout << "arr3 elements: ";
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 4: Test deep copy" << std::endl;
    // Modify the original array (arr2)
    arr2[0] = 0; 
    arr2[4] = 42;

    std::cout << "arr2 after modification: ";
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr3 (should be unchanged): ";
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    // Now, modify the copied array (arr3)
    arr3[1] = 200; 
    arr3[3] = 404;

    std::cout << "arr2 (should remain unchanged): ";
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "arr3 after modification (should reflect changes): ";
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "--------------------------" << std::endl;
    std::cout << "Test 5: Test assignment operator" << std::endl;
    Array<int> arr4(3);
    arr4[0] = 100;
    arr4[1] = 200;
    arr4[2] = 300;

    arr3 = arr4;  // Use the assignment operator
    std::cout << "arr3 after assignment from arr4: ";
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 6: Handling out-of-bounds access with exception" << std::endl;
    try {
        std::cout << "Trying to access out-of-bounds element in arr2: ";
        std::cout << arr2[10] << std::endl;  // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;  // Should print "Index out of bounds"
    }
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 7: Test with a double type" << std::endl;
    Array<double> arr5(4);
    for (unsigned int i = 0; i < arr5.size(); ++i) {
        arr5[i] = i * 1.1;  // Set values 0, 1.1, 2.2, 3.3
    }

    std::cout << "arr5 size: " << arr5.size() << std::endl;
    std::cout << "arr5 elements: ";
    for (unsigned int i = 0; i < arr5.size(); ++i) {
        std::cout << arr5[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;

    std::cout << "Test 8: Test with a string type" << std::endl;
    Array<std::string> arr6(3);  
    arr6[0] = "Test";
    arr6[1] = "Hello";
    arr6[2] = "World";

    std::cout << "arr6 size: " << arr6.size() << std::endl;
    std::cout << "arr6 elements: ";
    for (unsigned int i = 0; i < arr6.size(); ++i) {
        std::cout << arr6[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
