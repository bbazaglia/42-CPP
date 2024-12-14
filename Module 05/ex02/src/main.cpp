#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with high grade
        Bureaucrat bob("Bob", 1);

        // Create and test ShrubberyCreationForm
        std::cout << "\nTesting ShrubberyCreationForm with Bob (grade 1):" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        // Create and test RobotomyRequestForm
        std::cout << "\nTesting RobotomyRequestForm with Bob (grade 1):" << std::endl;
        RobotomyRequestForm robotomy("Alice");
        bob.signForm(robotomy);
        bob.executeForm(robotomy);

        // Create and test PresidentialPardonForm
        std::cout << "\nTesting PresidentialPardonForm with Bob (grade 1):" << std::endl;
        PresidentialPardonForm pardon("Charlie");
        bob.signForm(pardon);
        bob.executeForm(pardon);

        // Create a Bureaucrat with lower grade
        Bureaucrat alice("Alice", 50);

        // Attempt to sign and execute forms with lower grade Bureaucrat
        std::cout << "\nTesting ShrubberyCreationForm with Alice (grade 50):" << std::endl;
        ShrubberyCreationForm shrubbery2("garden");
        alice.signForm(shrubbery2);
        alice.executeForm(shrubbery2);

        std::cout << "\nTesting RobotomyRequestForm with Alice (grade 50):" << std::endl;
        RobotomyRequestForm robotomy2("Bob");
        alice.signForm(robotomy2);
        alice.executeForm(robotomy2);

        std::cout << "\nTesting PresidentialPardonForm with Alice (grade 50):" << std::endl;
        PresidentialPardonForm pardon2("Dave");
        alice.signForm(pardon2);
        alice.executeForm(pardon2);

        // Create a Bureaucrat with very low grade
        Bureaucrat charlie("Charlie", 150);

        // Attempt to sign and execute forms with very low grade Bureaucrat
        std::cout << "\nTesting ShrubberyCreationForm with Charlie (grade 150):" << std::endl;
        ShrubberyCreationForm shrubbery3("park");
        charlie.signForm(shrubbery3);
        charlie.executeForm(shrubbery3);

        std::cout << "\nTesting RobotomyRequestForm with Charlie (grade 150):" << std::endl;
        RobotomyRequestForm robotomy3("Eve");
        charlie.signForm(robotomy3);
        charlie.executeForm(robotomy3);

        std::cout << "\nTesting PresidentialPardonForm with Charlie (grade 150):" << std::endl;
        PresidentialPardonForm pardon3("Frank");
        charlie.signForm(pardon3);
        charlie.executeForm(pardon3);

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}