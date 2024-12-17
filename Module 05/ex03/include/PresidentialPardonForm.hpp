#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(std::string const target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    ~PresidentialPardonForm();

    // Member functions 
    void executeAction() const;
};

#endif