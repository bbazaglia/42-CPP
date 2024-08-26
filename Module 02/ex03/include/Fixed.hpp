#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits; 
public:
    // Constructors and destructor
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    // Copy constructor and assignment operator
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed &other);

    // Getter and setter
    int getRawBits() const;
    void setRawBits(int const raw);

    // Conversion functions
    float toFloat() const;
    int toInt() const;

    // Comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Increment and decrement operators
    Fixed& operator++();       
    Fixed operator++(int);    
    Fixed& operator--();       
    Fixed operator--(int);     

    // Static member functions for min and max
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Non-member function for output stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
