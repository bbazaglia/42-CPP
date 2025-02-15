#include <iostream>
#include <list>
#include <vector>
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

    std::cout << "Content of mstack1:" << std::endl;
    for (MutantStack<int>::iterator it = mstack1.begin(); it != mstack1.end(); ++it) {
        std::cout << *it << " ";
    }

    // Test copy constructor
    MutantStack<int> mstack2(mstack1);
    std::cout << "\nContent of mstack2 (copy of mstack1):" << std::endl;
    for (MutantStack<int>::iterator it = mstack2.begin(); it != mstack2.end(); ++it) {
        std::cout << *it << " ";
    }

    // Test assignment operator
    MutantStack<int> mstack3;
    mstack3 = mstack1;
    std::cout << "\nContent of mstack3 (assigned from mstack1):" << std::endl;
    for (MutantStack<int>::iterator it = mstack3.begin(); it != mstack3.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}


void testList() {
    MutantStack<int, std::list<int> > mstack;
    
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    
    std::cout << "\n------- Testing MutantStack with List -------" << std::endl;

    std::cout << "Iterating through List:" << std::endl;
    MutantStack<int, std::list<int> >::iterator it;
    for (it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nIterating through List in reverse:" << std::endl;
    MutantStack<int, std::list<int> >::reverse_iterator rit;
    for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << "\nIterating through List with const_iterator:" << std::endl;
    MutantStack<int, std::list<int> >::const_iterator cit;
    for (cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }

    std::cout << "\nIterating through List with const_reverse_iterator:" << std::endl;
    MutantStack<int, std::list<int> >::const_reverse_iterator crit;
    for (crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }

    std::cout << std::endl;
}

void testDeque() {
    MutantStack<int, std::deque<int> > mstack;
    
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    
    std::cout << "\n------- Testing MutantStack with Deque -------" << std::endl;

    std::cout << "Iterating through Deque:" << std::endl;
    MutantStack<int, std::deque<int> >::iterator it;
    for (it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nIterating through Deque in reverse:" << std::endl;
    MutantStack<int, std::deque<int> >::reverse_iterator rit;
    for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << "\nIterating through Deque with const_iterator:" << std::endl;
    MutantStack<int, std::deque<int> >::const_iterator cit;
    for (cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }

    std::cout << "\nIterating through Deque with const_reverse_iterator:" << std::endl;
    MutantStack<int, std::deque<int> >::const_reverse_iterator crit;
    for (crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    
    std::cout << std::endl;
}

void testVector() {
    MutantStack<int, std::vector<int> > mstack;
    
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    
    std::cout << "\n------- Testing MutantStack with Vector -------" << std::endl;

    std::cout << "Iterating through Vector:" << std::endl;
    MutantStack<int, std::vector<int> >::iterator it;
    for (it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nIterating through Vector in reverse:" << std::endl;
    MutantStack<int, std::vector<int> >::reverse_iterator rit;
    for (rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << "\nIterating through Vector with const_iterator:" << std::endl;
    MutantStack<int, std::vector<int> >::const_iterator cit;
    for (cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }

    std::cout << "\nIterating through Vector with const_reverse_iterator:" << std::endl;
    MutantStack<int, std::vector<int> >::const_reverse_iterator crit;
    for (crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }

    std::cout << std::endl;
}

int main() {
    testSubject();
    testCopyAndAssignment();
    testList();
    testDeque();
    testVector();
    return 0;
}