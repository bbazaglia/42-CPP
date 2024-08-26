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

// Arithmetic operators
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

Fixed Fixed::operator/(const Fixed &other) const {
    if (other._fixedPointValue == 0) {
        throw std::runtime_error("Division by zero");
    }
    Fixed result;
    result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
    return result;
}

// Increment and decrement operators
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
    this->_fixedPointValue -= 1; 
    return *this;               
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);           
    this->_fixedPointValue -= 1; 
    return temp;               
}

// Static member functions for min and max
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