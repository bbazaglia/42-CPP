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
    std::stack<int> _stack;
    bool _isvalidaExpression(std::string expression);
    bool _isValidOperand(std::string token);

}

#endif