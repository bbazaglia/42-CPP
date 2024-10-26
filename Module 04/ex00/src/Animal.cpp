#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << "Animal: Default Constructor called." << std::endl;
}

Animal::Animal(const Animal& copy) : _type(copy._type) {
    std::cout << "Animal: Copy Constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& copy) {
    std::cout << "Animal: Copy Assignment Operator called." << std::endl;
    if (this != &copy) {  
        _type = copy._type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: Destructor called." << std::endl;
}

std::string Animal::getType() const {
    return _type;
}

// outputs a message and doesn’t modify any member data as it's a read-only operation
void Animal::makeSound() const {
    std::cout << "Some animal sound" << std::endl;
}


