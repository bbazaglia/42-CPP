#include <iostream>
#include "MutantStack.hpp"

void testSubject() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "------ Testing Subject -------" << std::endl;
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Iterating through Subject:" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::stack<int> s(mstack);
}

void testCopyAndAssignment() {
    MutantStack<int> mstack1;
    mstack1.push(1);
    mstack1.push(2);
    mstack1.push(3);

    std::cout << "\n------- Testing Copy Constructor and Assignment Operator -------" << std::endl;

    // Test copy constructor
    MutantStack<int> mstack2(mstack1);
    printStackContent(mstack1, "mstack1");
    printStackContent(mstack2, "mstack2 (copy of mstack1)");

    // Test assignment operator
    MutantStack<int> mstack3;
    mstack3 = mstack1;
    printStackContent(mstack3, "mstack3 (assigned from mstack1)");
}


int main() {
    testSubject();
    testCopyAndAssignment();
    testContainer<std::list<int> >("List");
    testContainer<std::deque<int> >("Deque");
    testContainer<std::vector<int> >("Vector");

}