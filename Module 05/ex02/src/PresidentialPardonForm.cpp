#include "PresidentialPardonForm.hpp"

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const target) 
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) 
    : AForm(other), _target(other._target) {}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Member function to execute the action
void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}