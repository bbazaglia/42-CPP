#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class AForm {
public:
    // Constructors and Destructor
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExecute, const std::string target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    ~AForm();

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    std::string const getTarget() const;

    // Member functions
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor) const;

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};


protected:
    virtual void executeAction() const = 0;

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    std::string const _target;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif 

/*
    The executeAction is declared as protected to restrict its access to the class itself and its derived classes.
    This ensures that only the class AForm and any classes that inherit from AForm can call this function.
    
    Reasons for this include:
     1. Encapsulation: Prevents external classes from calling this function directly, maintaining the integrity of the class's internal state.
     2. Inheritance: As a pure virtual function, it must be overridden by derived classes, and making it protected ensures only derived classes can provide an implementation.
     3. Controlled Access: Ensures that actions performed by this function are executed in a controlled manner, typically by the class itself or its subclasses.
*/   
