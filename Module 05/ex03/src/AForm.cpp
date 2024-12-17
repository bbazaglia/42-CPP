#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150), _target("unknown") {}

// Parameterized constructor
AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute, std::string const target)
	:	_name(name),
		_isSigned(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_target(target) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw AForm::GradeTooHighException();
	}
	else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}

// Copy constructor
AForm::AForm(AForm const &other) 
	:	_name(other._name),
		_isSigned(other._isSigned),
		_gradeToSign(other._gradeToSign),
		_gradeToExecute(other._gradeToExecute),
		_target(other._target) {}

// Copy assignment operator
AForm &AForm::operator=(AForm const &other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

std::string const AForm::getTarget() const {
	return _target;
}

// Member function to sign the form
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    }
    _isSigned = true;
}

// Executes the form if it is signed and the executor has the required grade
void AForm::execute(Bureaucrat const &executor) const {
    if (!this->isSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    this->executeAction();
}

// Exception classes
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed.";
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade to sign: " << form.getGradeToSign()
       << ", grade to execute: " << form.getGradeToExecute();
    return os;
}