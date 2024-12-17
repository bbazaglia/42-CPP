#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    else if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _grade = other._grade; 
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

void Bureaucrat::incrementGrade() {
    try {
        if (_grade <= 1) {
            throw GradeTooHighException();
        }
        --_grade;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught for bureaucrat " << this->getName()
                  << " when trying to increment grade: " << e.what() << "\n"
                  << "Current grade: " << this->getGrade() << std::endl;
    }
}

void Bureaucrat::decrementGrade() {
    try {
        if (_grade >= 150) {
            throw GradeTooLowException();
        }
        ++_grade;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught for bureaucrat " << this->getName()
                  << " when trying to decrement grade: " << e.what() << "\n"
                  << "Current grade: " << this->getGrade() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
