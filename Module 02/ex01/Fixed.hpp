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

// By default, the << operator is defined for built-in types like int, float, std::string, etc. 
// However, for user-defined types (like Fixed), the compiler does not know how to handle the << operator unless you explicitly define it.
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif