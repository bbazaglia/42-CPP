#include "LiteralValidator.hpp"

bool LiteralValidator::isCharLiteral(const std::string &input) {
    return input.length() == 1 && isprint(input[0]) && !isdigit(input[0]);
}

bool LiteralValidator::isIntLiteral(const std::string &input) {
    if (input.empty())
        return false;

    // Manually convert string to integer
    std::stringstream numStream(input); 
    int value;
    numStream >> value;

    // in_avail() returns the number of characters available for reading in the buffer
    // if there are remaining characters, the input strig was not fully consumed
    if (numStream.fail() || numStream.rdbuf()->in_avail() != 0) {
        return false;
    }

    return true;
}

bool LiteralValidator::isFloatLiteral(const std::string &input) {
    if (input == "-inff" || input == "+inff" || input == "nanf")
        return true;

    size_t len = input.length();
    if (len < 2 || input[len - 1] != 'f')  // Check if it ends with 'f'
        return false;

    std::string floatPart = input.substr(0, len - 1);  // Remove 'f'
    return isDoubleLiteral(floatPart);  // Reuse isDoubleLiteral for validation
}

bool LiteralValidator::isDoubleLiteral(const std::string &input) {
    char* end;

    errno = 0; // Reset errno to 0 before calling strtod to clear any previous errors

    // strtod converts the initial part of the string to a double and sets 'end' to point to the first character after the number
    strtod(input.c_str(), &end);

    // Check for conversion errors
    // errno == ERANGE: Check if the conversion resulted in an overflow or underflow
    // end == input.c_str(): Check if no characters were converted, meaning the input string did not start with a valid number
    // *end != '\0': Check if there are any characters left in the string after the number
    if (errno == ERANGE || end == input.c_str() || *end != '\0') {
        return (false); 
    }

    return (true);
}