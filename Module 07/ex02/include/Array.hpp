#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> 

// Template class declaration
template <typename T>
class Array {
private:
    T* data;                 
    unsigned int _size;    
    
public:
    // Default constructor
    Array();

    // Parameterized constructor
    Array(unsigned int n);

    // Copy constructor
    Array(const Array& other);

    // Assignment operator
    Array& operator=(const Array& other);

    // Subscript operator
    T& operator[](unsigned int index);

    // Size function
    unsigned int size() const;

    // Destructor
    ~Array();
};

#include "Array.tpp" 

#endif  
