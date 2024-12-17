#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}


Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) {
    
    std::string formNames[] = { "shrubbery creation", "robotomy request", "presidential pardon" };

    bool isValidForm = false;

	int formIndex = 0;

	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			formIndex = i;
            isValidForm = true;
			break;
		}
	}

	if (isValidForm == false) {
		std::cout << "Intern can't create "<< formName <<" form." << std::endl;
		return (NULL);
	}

	std::cout << "Intern creates " << formName << " form." << std::endl;
	switch(formIndex) {
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			std::cout << "Form not found" << std::endl;
			return (NULL);
	}
}