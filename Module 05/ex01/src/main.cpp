#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    try {
        // Test creating Bureaucrat with valid grade
        Bureaucrat john("John Doe", 42);
        std::cout << john << std::endl;

        // Test creating Bureaucrat with invalid grade (too high)
        try {
            Bureaucrat invalidHigh("Invalid High", 0);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test creating Bureaucrat with invalid grade (too low)
        try {
            Bureaucrat invalidLow("Invalid Low", 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test incrementing and decrementing Bureaucrat grade
        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        // Test creating Form with valid grades
        Form formA("Form A", 50, 100);
        std::cout << formA << std::endl;

        // Test creating Form with invalid grade (too high)
        try {
            Form invalidFormHigh("Invalid Form High", 0, 100);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test creating Form with invalid grade (too low)
        try {
            Form invalidFormLow("Invalid Form Low", 50, 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test signing form with Bureaucrat
        try {
            john.signForm(formA);
            std::cout << formA << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

        // Test signing form with Bureaucrat with insufficient grade
        Bureaucrat lowGradeBureaucrat("Low Grade", 100);
        try {
            lowGradeBureaucrat.signForm(formA);
        } catch (const std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception caught in main: " << e.what() << std::endl;
    }

    return 0;
}