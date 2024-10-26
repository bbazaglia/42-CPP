#include "Cat.hpp"

Cat::Cat() {

    _type = "Cat";
    std::cout << "Cat: Default Constructor called. 🐱" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy) {

    std::cout << "Cat: Copy Constructor called." << std::endl;
    *this = copy;
}

Cat& Cat::operator=(const Cat& copy) {

    std::cout << "Cat: Copy Assingment Operator called." << std::endl;

    if(this != &copy)
        _type = copy._type;
    return *this;
}

Cat::~Cat() {

    std::cout << "Cat: Destructor called." << std::endl;
}

void Cat::makeSound() const {

    std::cout << "Meow Meow" << std::endl;
}