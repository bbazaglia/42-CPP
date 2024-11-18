#include "WrongCat.hpp"

WrongCat::WrongCat() : _type("WrongCat") {
    std::cout << "WrongCat: Default Constructor called. 🐄" << std::endl;
}

/* The member initializer list is used to initialize base classes and member variables before the body of the constructor is executed.
 WrongAnimal(copy): This calls the copy constructor of the base class WrongAnimal to initialize the base part of the WrongCat object using the copy object.
_type(copy._type): This initializes the _type member variable of the WrongCat object using the _type member variable of the copy object.

Why Use Member Initializer List?
Base Class Initialization: The base class constructor must be called before the derived class constructor body is executed. Using the member initializer list ensures that the base class is properly initialized.
Const and Reference Members: Const and reference members must be initialized in the member initializer list because they cannot be assigned values in the constructor body.
Efficiency: Initializing members in the member initializer list can be more efficient than assigning values in the constructor body, as it avoids default construction followed by assignment.
*/
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
