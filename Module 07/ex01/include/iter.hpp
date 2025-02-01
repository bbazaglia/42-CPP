#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T* arr, size_t len, Func func) {
    for (size_t i = 0; i < len; ++i) {
        func(arr[i]);  
    }
}

template <typename T>
void printElement(T element) {
    std::cout << element << " ";
}

#endif