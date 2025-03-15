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
