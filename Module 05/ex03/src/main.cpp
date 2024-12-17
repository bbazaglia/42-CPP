#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Intern intern;

    std::cout << "✅ Testing with valid forms:" << std::endl;

    AForm *form1 = intern.makeForm("shrubbery creation", "home");
    if (form1) {
        std::cout << "Form created: " << form1->getName() << std::endl;
        delete form1;
    }
    std::cout << std::endl;

    AForm *form2 = intern.makeForm("robotomy request", "robot");
    if (form2) {
        std::cout << "Form created: " << form2->getName() << std::endl;
        delete form2;
    }
    std::cout << std::endl;


    AForm *form3 = intern.makeForm("presidential pardon", "president");
    if (form3) {
        std::cout << "Form created: " << form3->getName() << std::endl;
        delete form3;
    }
    std::cout << std::endl;


    std::cout << "❌ Testing with unknown forms:" << std::endl;

    AForm *form4 = intern.makeForm("The Hitchhiker's Guide to the Galaxy", "target");
    if (!form4) {
        std::cout << "Form creation failed for unknown form." << std::endl;
    }

    return 0;
}