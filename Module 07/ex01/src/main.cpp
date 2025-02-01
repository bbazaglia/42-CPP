#include "iter.hpp"

int main() {
    // Testing with an array of integers
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    iter(arr, len, printElement<int>);
    std::cout << std::endl;
    
    // Testing with an array of doubles
    double arr2[] = {1.1, 2.2, 3.3, 4.4};
    len = sizeof(arr2) / sizeof(arr2[0]);
    iter(arr2, len, printElement<double>);
    std::cout << std::endl;

    return 0;
}