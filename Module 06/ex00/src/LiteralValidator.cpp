#include "LiteralValidator.hpp"

bool LiteralValidator::isCharLiteral(const std::string &input) {
    return input.length() == 3 && input[0] == '\'' && input[2] == '\'' && isprint(input[1]);
}

bool LiteralValidator::isIntLiteral(const std::string &input) {
    if (input.empty())
        return false;

    // Manually convert string to integer
    std::stringstream numStream(input);
    int value;
    numStream >> value;

    // Check if there are any characters left in the buffer after the extraction
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
	errno = 0;
	strtod(input.c_str(), &end);

	if (errno == ERANGE || end == input.c_str() || *end != '\0') {
		return (false);
	}

	return (true);
}
