#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << "WrongAnimal: Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) : _type(copy._type) {
    std::cout << "WrongAnimal: Copy Constructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy) {
    std::cout << "WrongAnimal: Copy Assignment Operator called." << std::endl;
    if (this != &copy) {  
        _type = copy._type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: Destructor called." << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "Some WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
    return _type;
}