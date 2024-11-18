#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat") {
    std::cout << "WrongCat: Default Constructor called. 🐄" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy), _type(copy._type) {
    std::cout << "WrongCat: Copy Constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
    std::cout << "WrongCat: Copy Assignment Operator called." << std::endl;
    if (this != &copy) {  
        _type = copy._type;
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: Destructor called." << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Moo Moo" << std::endl;
}
