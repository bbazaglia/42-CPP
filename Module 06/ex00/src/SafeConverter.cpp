#include "SafeConverter.hpp"

void safeCharConverter(double input) {
    // Input is outside the valid range for a char or is NaN
    if (input > 127 || input < -128 || input != input) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (std::isprint(static_cast<char>(input))) {
        std::cout << "char: " << static_cast<char>(input) << std::endl;
    }
    else {
        // If the input is valid but not printable
        std::cout << "char: non displayable" << std::endl;
    }
}

void	safeIntConverter(double input) {
	if (input > std::numeric_limits<int>::max()
		|| input < std::numeric_limits<int>::min()
		|| input != input) {
		std::cout << "int: impossible" << std::endl;
		}
	else {
		std::cout << "int: " << static_cast<int>(input) << std::endl;
	}
}

void	safeFloatConverter(double input) {
	if (std::isinf(input)) { 
		std::cout << "float: " << (input > 0 ? "+inff" : "-inff")  << std::endl;
	}
	else if (input > std::numeric_limits<float>::max()
		|| input < -std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
	}
	else if (input - static_cast<int>(input) == 0) {
		std::cout << "float: " << static_cast<float>(input) << ".0f" << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(input) << "f"  << std::endl;
	}
}

void	safeDoubleConverter(double input) {
	if (std::isinf(input)) {
		std::cout << "double: " << (input > 0 ? "+inf" : "-inf") << std::endl;
	}
	else if (input - static_cast<int>(input) == 0) {
		std::cout << "double: " << static_cast<double>(input) << ".0" << std::endl;
	}
	else {
		std::cout << "double: " << static_cast<double>(input) << std::endl;
	}
}