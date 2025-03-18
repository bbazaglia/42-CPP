#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>

class RPN {
public:
    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN & operator=(const RPN &other);

    void solveExpression(const std::string &expression);

private:
    /* Using a stack as our container:
        LIFO (Last-In-First-Out) matches how RPN operators work on recent operands
        Naturally handles the sequential processing of the expression */
    std::stack<int> _stack;

    bool _isValidOperand(std::string token);
    bool _processToken(std::stack<int> &stack, const std::string &token);
};


#endif