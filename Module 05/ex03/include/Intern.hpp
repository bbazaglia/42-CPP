#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    // Orthodox Canonical Form
    Intern();
    Intern(std::string const target);
	Intern(Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();

    // Member functions 
    AForm *makeForm(std::string formName, std::string formTarget);
};

#endif