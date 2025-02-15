#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value) throw(std::runtime_error) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("Error: Value not found inside container");
    }
    return it;
}

template<typename T>
void testEasy(T& container, int value) {
    try {
        typename T::iterator it = easyfind(container, value);
        std::cout << "Value found: " << *it << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
}

template <typename T>
void printContainer(const T& container) {
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

#endif


/* STL containers are classified into three categories:
1. Sequence Containers: store elements in a linear order, allowing indexed or sequential access.
    * std::vector – dynamic array that can grow/shrink as needed.
    * std::list – doubly linked list.
    * std::deque – double-ended queue.
    
2. Associative Containers: use key-value pairs and maintain elements in sorted order.
    * std::set – stores unique keys in sorted order.
    * std::map – stores key-value pairs with unique keys.
    * std::multiset – stores keys in sorted order allowing duplicates.
    
3. Container Adapters: provide a restricted interface to other containers.
    * std::stack – provides LIFO access to elements.
    * std::queue – provides FIFO access to elements.
    * std::priority_queue – provides access to the largest/greatest element.


 *  About iterators:
    Iterator is an abstract object that provides a uniform interface for traversing containers. 
    It behaves like a pointer in terms of accessing and iterating over elements, but it can be more flexible and designed to work with any container type.

    STL containers use iterators to traverse elements.      
    std::vector<int> v = {10, 20, 30};
    std::vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";  // Output: 10 20 30
}
*/