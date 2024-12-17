#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

// Prevent copying (by defining but not implementing)
ScalarConverter::ScalarConverter(const ScalarConverter& other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    return *this;
}

void ScalarConverter::convert(const std::string& literal) {
    
}