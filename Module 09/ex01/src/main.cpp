#include "RPN.hpp"
#include <cstring> 

void testRPN() {
    RPN calculator;
    
    // Test basic operations
    std::cout << "Test: \"3 4 +\" (Expected: 7)" << std::endl;
    calculator.solveExpression("3 4 +");
    
    std::cout << "\nTest: \"5 2 -\" (Expected: 3)" << std::endl;
    calculator.solveExpression("5 2 -");
    
    std::cout << "\nTest: \"3 4 *\" (Expected: 12)" << std::endl;
    calculator.solveExpression("3 4 *");
    
    std::cout << "\nTest: \"6 2 /\" (Expected: 3)" << std::endl;
    calculator.solveExpression("6 2 /");
    
    // Test multiple operations
    std::cout << "\nTest: \"3 4 + 2 *\" (Expected: 14)" << std::endl;
    calculator.solveExpression("3 4 + 2 *");
    
    std::cout << "\nTest: \"3 4 2 + *\" (Expected: 18)" << std::endl;
    calculator.solveExpression("3 4 2 + *");
    
    // Test complex expression
    std::cout << "\nTest: \"5 1 2 + 4 * + 3 -\" (Expected: 14)" << std::endl;
    calculator.solveExpression("5 1 2 + 4 * + 3 -");
    
    // Test error cases
    std::cout << "\nTest: \"7 0 /\" (Expected: Error)" << std::endl;
    calculator.solveExpression("7 0 /");
    
    std::cout << "\nTest: \"1 +\" (Expected: Error)" << std::endl;
    calculator.solveExpression("1 +");
    
    std::cout << "\nTest: \"10 2 +\" (Expected: Error)" << std::endl;
    calculator.solveExpression("10 2 +");
}


int main(int argc, char **argv) {

    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN [inverted Polish mathematical expression]" << std::endl;
        return 1;
    }

    // run sample tests
    if (std::strcmp(argv[1], "test") == 0)
    {
        testRPN(); 
    }
    
    // perform ordinary behavior
    else {
        RPN calculator;
        
        std::string expression = argv[1];
        
        calculator.solveExpression(expression);
    }

    return 0;
} 