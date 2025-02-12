#include "Span.hpp"

Span::Span() : _size(0), _numbers() {}

Span::Span(unsigned int n) : _size(n), _numbers() {}

Span::Span(Span const &other) : _size(other._size), _numbers(other._numbers) {}

Span &Span::operator=(Span const &other)
{
    if (this != &other)
    {
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n) throw(std::overflow_error)
{
    if (_numbers.size() >= _size)
        throw std::overflow_error("Span is full");
    _numbers.push_back(n);
}

int Span::shortestSpan() const throw(std::underflow_error)
{
    if (_numbers.size() < 2)
        throw std::underflow_error("Span is empty or has only one element");
    
    // Create a copy of the _numbers vector and sort it
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    // Initialize the minimum difference to the maximum possible integer value
    int min = INT_MAX;

    // Iterate through the sorted vector 
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; it++)
    {
        // Calculate the difference between the current element and the next element
        int diff = *(it + 1) - *it;

        // Update the minimum difference if the current difference is smaller
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() const throw(std::underflow_error)
{
    if (_numbers.size() < 2)
        throw std::underflow_error("Span is empty or has only one element");
    
    // Create a copy of the _numbers vector and sort it
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    // Return the difference between the largest and smallest elements
    return sorted.back() - sorted.front();
}

void Span::generateRandomNumbers(int n) throw(std::overflow_error)
{
    if (_numbers.size() + n > _size)
        throw std::overflow_error("Span is full");
    
    // Seed the random number generator
    srand(time(NULL));

    // Generate n random numbers and add them to the _numbers vector
    for (int i = 0; i < n; i++)
        _numbers.push_back(rand());
}