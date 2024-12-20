#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45, "unknown") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
    : AForm("RobotomyRequestForm", 72, 45, target) {}

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
    std::srand(std::time(0)); // Seed the random number generator
    std::cout << "Drilling noises..." << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << getTarget() << " failed." << std::endl;
    }
}