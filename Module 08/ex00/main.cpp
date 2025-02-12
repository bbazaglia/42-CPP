#include "easyfind.hpp"

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

    std::cout << "Testing with std::vector:" << std::endl;
    testEasy(vec, 20);
    testEasy(vec, 50);  // Not found case

    std::cout << "\nTesting with std::list:" << std::endl;
    testEasy(lst, 15);
    testEasy(lst, 100);  // Not found case

    std::cout << "\nTesting with std::deque:" << std::endl;
    testEasy(deq, 7);
    testEasy(deq, 42);  // Not found case

    return 0;
}