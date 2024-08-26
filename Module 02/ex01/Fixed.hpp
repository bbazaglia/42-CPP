#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _fixedPointValue;
    static const int _fractionalBits;
public:
    // Constructors and destructor
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    // Copy and assignation
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed &other);

    // Overload operators
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    // Conversion functions
    float toFloat( void ) const;
    int toInt( void ) const;
};

// Define how to ouput an object of type Fixed to an output stream
// The compiler does not know how to handle custom types with the << operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif