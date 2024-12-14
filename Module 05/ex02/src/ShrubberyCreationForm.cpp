#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137, "unknown") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
    : AForm("Shrubbery Creation", 145, 137, target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) 
    : AForm(other) {}

// Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Member function to execute the action
void ShrubberyCreationForm::executeAction() const {
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";

    file.close();
}