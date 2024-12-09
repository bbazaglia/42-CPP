#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        // Create a Bureaucrat with a valid grade
        Bureaucrat john("John", 75);
        std::cout << john << std::endl;

        // Increment grade within valid range
        john.incrementGrade();
        std::cout << "After incrementing grade: " << john << std::endl;

        // Decrement grade within valid range
        john.decrementGrade();
        std::cout << "After decrementing grade: " << john << std::endl;

        // Attempt to create a Bureaucrat with a grade too high
        try {
            Bureaucrat alice("Alice", 0);
        } catch (const std::exception& e) {
            std::cerr << "Exception during Alice creation: " << e.what() << std::endl;
        }

        // Attempt to create a Bureaucrat with a grade too low
        try {
            Bureaucrat bob("Bob", 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception during Bob creation: " << e.what() << std::endl;
        }

        // Increment grade to trigger GradeTooHighException
        Bureaucrat jane("Jane", 2);
        std::cout << jane << std::endl;
        jane.incrementGrade();
        std::cout << "After incrementing grade: " << jane << std::endl;
        jane.incrementGrade(); // This should trigger an exception

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
