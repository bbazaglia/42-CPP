#include "Dog.hpp"

Dog::Dog(void) {

    _type = "Dog";
    std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy) {

    std::cout << "Dog: Copy Constructor called." << std::endl;
    *this = copy;
}

Dog& Dog::operator=(const Dog& copy) {

    std::cout << "Dog: Copy Assingment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
        
    return (*this);
}

Dog::~Dog(void) {

    std::cout << "Dog: Destructor called." << std::endl;
}

void Dog::makeSound(void) const {

    std::cout << "Dog: Woof Woof!" << std::endl;
}