#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib> 
#include <ctime>

class Span {
private:
    unsigned int _size;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int n);
    Span(Span const &other);
    Span &operator=(Span const &other);
    ~Span();

    void addNumber(int n) throw(std::overflow_error);
    int shortestSpan() const throw(std::underflow_error);
    int longestSpan() const throw(std::underflow_error);

    void generateRandomNumbers(int n) throw(std::overflow_error);
};

#endif