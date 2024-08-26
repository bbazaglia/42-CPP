#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int value) {
    this->_fixedPointValue = value << Fixed::_fractionalBits;
}

Fixed::Fixed(const float value) {
    int convertedValue = roundf(value * (1 << Fixed::_fractionalBits));
    this->setRawBits(convertedValue);
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << Fixed::_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> Fixed::_fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

/* Arithmetic operators
 * this represents the object on which the operator function was called (left-hand side of the operator).
 * other represents the object passed to the operator function (right-hand side of the operator).
 */
Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
    return result;
}


Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) >> _fractionalBits;
    return result;
}

/* Bit Shift (<< _fractionalBits): Shifts the bits of the numerator (this->_fixedPointValue) to the left by the number of fractional bits. 
This multiplication by 2^_fractionalBits helps maintain precision in fixed-point division.
*/
Fixed Fixed::operator/(const Fixed &other) const {
    if (other._fixedPointValue == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
    return result;
}

/* Increment and decrement operators
 * Pre-increment and Pre-decrement directly modify the object before returning it.
 * These operators increment or decrement the value of the variable before it is used in an expression.
 * 
 * Post-increment and Post-decrement operate on the value after making a copy of the original.
 * These operators increment or decrement the value of the variable after it is used in an expression.
 */
Fixed& Fixed::operator++() {
    this->_fixedPointValue += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue += 1;
    return temp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue -= 1; // Decrement the value
    return *this;                // Return the updated object itself
}


Fixed Fixed::operator--(int) {
    Fixed temp(*this);           // Create a copy of the current object
    this->_fixedPointValue -= 1; // Decrement the value
    return temp;                // Return the copy that still has the old value
}


/* Static member functions for min and max
 * These functions are static because they do not depend on a specific instance of the class. 
 * Instead, they operate on the two Fixed objects passed to them.
 *
 * Non-const reference version allows you to pass modifiable Fixed objects as arguments and modify them through the references.
 * Const reference version takes constant references to Fixed objects, meaning the function cannot modify the objects being passed.
 */
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() < b.getRawBits()) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a.getRawBits() > b.getRawBits()) ? a : b;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}