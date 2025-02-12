#include "Span.hpp"
#include <list>

int main() {

    std::cout << "Testing basic functionality..." << std::endl;
    
    Span firstSpan(5);
    firstSpan.addNumber(6);
    firstSpan.addNumber(3);
    firstSpan.addNumber(17);
    firstSpan.addNumber(9);
    firstSpan.addNumber(11);
    
    std::cout << "Shortest span: " << firstSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << firstSpan.longestSpan() << std::endl;

    std::cout << "\nTesting exceptions..." << std::endl;
    
    Span secondSpan(3);
    
    // Test empty span
    try {
        secondSpan.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception caught (empty): " << e.what() << std::endl;
    }
    
    // Test single element
    secondSpan.addNumber(5);
    try {
        secondSpan.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Exception caught (single element): " << e.what() << std::endl;
    }
    
    // Test overflow
    secondSpan.addNumber(2);
    secondSpan.addNumber(9);
    try {
        secondSpan.addNumber(1);
    } catch (const std::exception& e) {
        std::cout << "Exception caught (overflow): " << e.what() << std::endl;
    }


    std::cout << "\nTesting large numbers..." << std::endl;

    Span thirdSpan(10000);
    thirdSpan.generateRandomNumbers(10000);

    std::cout << "Shortest span: " << thirdSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << thirdSpan.longestSpan() << std::endl;

    return 0;
}