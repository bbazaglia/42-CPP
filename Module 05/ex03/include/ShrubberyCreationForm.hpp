#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const target);
	ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    ~ShrubberyCreationForm();

    // Member functions 
    void executeAction() const;
};

#endif