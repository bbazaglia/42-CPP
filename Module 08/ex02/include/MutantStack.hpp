#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <typeinfo>

// reference: https://en.cppreference.com/w/cpp/container/stack
// reference: https://en.cppreference.com/w/cpp/container/deque

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
    // Typedefs for iterator types
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Constructors
    MutantStack() : std::stack<T, Container>() {}
    
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other)
            std::stack<T, Container>::operator=(other);
        return *this;
    }
    
    ~MutantStack() {}

    // Iterator functions
    iterator begin() { return this->c.begin(); }
    
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    
    const_iterator end() const { return this->c.end(); }
    
    reverse_iterator rbegin() { return this->c.rbegin(); }
    
    reverse_iterator rend() { return this->c.rend(); }
    
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    
    const_reverse_iterator rend() const { return this->c.rend(); }
};

// Helper function to iterate over the stack
template <typename Container>
void iterateAndPrint(MutantStack<int, Container>& mstack) {
    std::cout << "Iterating through container:" << std::endl;
    for (typename MutantStack<int, Container>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << "\nIterating through container in reverse:" << std::endl;
    for (typename MutantStack<int, Container>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << " ";
    }

    std::cout << "\nIterating through container with const_iterator:" << std::endl;
    for (typename MutantStack<int, Container>::const_iterator cit = mstack.begin(); cit != mstack.end(); ++cit) {
        std::cout << *cit << " ";
    }

    std::cout << "\nIterating through container with const_reverse_iterator:" << std::endl;
    for (typename MutantStack<int, Container>::const_reverse_iterator crit = mstack.rbegin(); crit != mstack.rend(); ++crit) {
        std::cout << *crit << " ";
    }
    std::cout << std::endl;
}

// Function to get readable container type name
std::string getReadableContainerName(const std::string& mangledName) {
    if (mangledName == typeid(std::deque<int>).name()) {
        return "deque";
    } else if (mangledName == typeid(std::list<int>).name()) {
        return "list";
    } else if (mangledName == typeid(std::vector<int>).name()) {
        return "vector";
    } else {
        return "unknown";
    }
}

// Template function to test any container type with MutantStack
template <typename Container>
void testContainer(const std::string& containerName) {
    MutantStack<int, Container> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    mstack.push(5);
    mstack.push(6);
    
    std::cout << "\n------- Testing MutantStack with " << containerName << " -------" << std::endl;
    iterateAndPrint(mstack);
    std::cout << std::endl;
    std::cout << "Container type: " << getReadableContainerName(typeid(Container).name()) << std::endl;
}

// Helper function to print the content of any stack
template <typename T>
void printStackContent(const MutantStack<T>& mstack, const std::string& stackName) {
    std::cout << "Content of " << stackName << ":" << std::endl;
        for (typename MutantStack<T>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}


#endif