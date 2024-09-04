#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/* Static members are shared among all instances of the class, and they are not tied to any particular object. 
To access static members, you must qualify them with the class name (Fixed::) because they are not part of any specific object instance. */
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = value << Fixed::_fractionalBits; // the integer part is shifted left by 8 bits to make room for the fractional part
}

/* Scaling: 1 << Fixed::_fractionalBits is used to scale the floating-point number into the fixed-point format.
Conversion: Multiplying value by this scaling factor converts it into a format that fits the fixed-point representation.
Rounding: roundf ensures that the result is an integer, which is necessary for fixed-point storage.*/
Fixed::Fixed(const float value)
{
    int convertedValue = roundf(value * (1 << Fixed::_fractionalBits));
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(convertedValue);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Initialize a new object as a copy of an existing object
Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
// Copy data from one existing object to another existing object (already initialized)
Fixed& Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        std::cout << "Copy assignment operator called" << std::endl;
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return (float)this->_fixedPointValue / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_fixedPointValue >> Fixed::_fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat(); // Output the fixed-point value as a float
    return os; // Return the stream to support chaining
}