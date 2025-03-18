#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    if (this != &other)
        *this = other;
}

RPN & RPN::operator=(const RPN &other) {
	if (this != &other) {}
        this->_stack = other._stack;
        
	return *this;
}

RPN::~RPN() {}

// single digit number check
bool RPN::_isValidOperand(std::string token) {
    return token.length() == 1 && std::isdigit(token[0]);
}

bool RPN::_processToken(std::stack<int> &stack, const std::string &token) {
    // if token is an operand
    if (_isValidOperand(token)) {
        stack.push(token[0] - '0');
    }
    // if token is an operator
    else if (token == "+" || token == "-" || token == "*" || token == "/") {

        // need at least two operands for an operation
        if (stack.size() < 2) {
            return false;
        }

        int secondOperand = stack.top();
        stack.pop();
        int firstOperand = stack.top();
        stack.pop();

        // check for division by zero
        if (token == "/" && secondOperand == 0) {
            return false;
        }

        // perform the operation
        if (token == "+") {
            stack.push(firstOperand + secondOperand);
        }
        else if (token == "-") {
            stack.push(firstOperand - secondOperand);
        }
        else if (token == "*") {
            stack.push(firstOperand * secondOperand);
        }
        else if (token == "/") {
            stack.push(firstOperand / secondOperand);
        } else {
            return false;  // invalid token
        }
    }

    return true;
}

void RPN::solveExpression(const std::string &expression) {
    // clear the stack before processing
    while (!_stack.empty()) {
        _stack.pop();
    }

    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (!_processToken(_stack, token)) {
            std::cout << "Error: Invalid expression" << std::endl;
            return;
        }
    }

    // after processing, there should be exactly one value left on the stack
    if (_stack.size() != 1) {
        std::cout << "Error: Invalid expression" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}
