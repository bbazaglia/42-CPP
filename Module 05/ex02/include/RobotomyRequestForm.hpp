#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();

    // Member functions 
    void executeAction() const;
};

#endif