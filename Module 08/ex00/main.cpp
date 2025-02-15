#include "easyfind.hpp"
#include <deque>
#include <vector>
#include <list>

// Reference: https://en.cppreference.com/w/cpp/container/vector

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    std::deque<int> deq;
    deq.push_back(7);
    deq.push_back(14);
    deq.push_back(21);

    std::cout << "std::vector: ";
    printContainer(vec);
    testEasy(vec, 20);
    testEasy(vec, 50);  // Not found case

    std::cout << "\nstd::list:  ";
    printContainer(lst);
    testEasy(lst, 15);
    testEasy(lst, 100);  // Not found case

    std::cout << "\nstd::deque: ";
    printContainer(deq);
    testEasy(deq, 7);
    testEasy(deq, 42);  // Not found case

    return 0;
}