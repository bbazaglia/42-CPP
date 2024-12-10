#include "RobotomyRequestForm.hpp"

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
    : AForm("Robotomy Request", 72, 45), _target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) 
    : AForm(other) {}

// Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Member function to execute the action
void RobotomyRequestForm::executeAction() const {
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
    }
}