#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input) {
    if (LiteralValidator::isCharLiteral(input)) {
        // Handle char literal
        char c = input[1]; // Extract character from 'c'
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    } else if (LiteralValidator::isIntLiteral(input)) {
        // Handle int literal
        try {
            int i = std::stoi(input);
            std::cout << "char: ";
            if (i >= std::numeric_limits<char>::min() &&
                i <= std::numeric_limits<char>::max() &&
                isprint(static_cast<char>(i))) {
                std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        } catch (...) {
            std::cerr << "Error: Conversion failed" << std::endl;
        }
    } else if (LiteralValidator::isFloatLiteral(input)) {
        // Handle float literal
        try {
            float f = std::stof(input);
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: ";
            if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
                std::cout << static_cast<int>(f) << std::endl;
            else
                std::cout << "impossible" << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        } catch (...) {
            std::cerr << "Error: Conversion failed" << std::endl;
        }
    } else if (LiteralValidator::isDoubleLiteral(input)) {
        // Handle double literal
        try {
            double d = std::stod(input);
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: ";
            if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
                std::cout << static_cast<int>(d) << std::endl;
            else
                std::cout << "impossible" << std::endl;
            std::cout << "float: ";
            if (d >= -std::numeric_limits<float>::max() && d <= std::numeric_limits<float>::max())
                std::cout << static_cast<float>(d) << "f" << std::endl;
            else
                std::cout << "impossible" << std::endl;
            std::cout << "double: " << d << std::endl;
        } catch (...) {
            std::cerr << "Error: Conversion failed" << std::endl;
        }
    } else {
        std::cerr << "Error: Invalid input" << std::endl;
    }
}
