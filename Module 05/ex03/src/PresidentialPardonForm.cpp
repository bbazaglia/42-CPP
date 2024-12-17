#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5, "unknown") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string const target) 
    : AForm("PresidentialPardonForm", 25, 5, target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) 
    : AForm(other) {}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Member function to execute the action
void PresidentialPardonForm::executeAction() const {
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}