#include "Dog.hpp"

Dog::Dog() : _brain(new Brain()) {
    _type = "Dog";
    std::cout << "Dog: Default Constructor called. 🐶" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy), _brain(new Brain(*(copy._brain))) {
    std::cout << "Dog: Copy Constructor called. 🐶" << std::endl;
}

Dog& Dog::operator=(const Dog& copy) {
    if (this != &copy) {
        Animal::operator=(copy);
        if (_brain) {
            delete _brain;
        }
        _brain = new Brain(*(copy._brain));
        _type = copy._type;
    }
    std::cout << "Dog: Copy Assignment Operator called. 🐶" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog: Destructor called. 🐶" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain(void) const {

    return (_brain);
}

void Dog::setBrain(Brain *brain) {

    _brain = brain;
}