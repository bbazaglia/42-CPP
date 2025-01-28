#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &input)
{
	double	literal = 0;
	bool	isConvertible = true;

	if (isCharLiteral(input))
	{
		std::cout << "Value is a --> char <--\n";
		literal = input[0];
	}
	else if (isIntLiteral(input))
	{
		std::cout << "Value is an --> int <--\n";
		literal = std::atoi(input.c_str());
	}
	else if (isFloatLiteral(input))
	{
		std::cout << "Value is a --> float <--\n";
		literal = std::atof(input.c_str());
	}
	else if (isDoubleLiteral(input))
	{
		std::cout << "Value is a --> double <--\n";
		literal = std::strtod(input.c_str(), NULL);
	}
	else
	{
	    isConvertible = false;
		std::cout << "Error: Unknown value type\n";
	}
	if (isConvertible)
	{
		safeCharConverter(literal);
		safeIntConverter(literal);
		safeFloatConverter(literal);
		safeDoubleConverter(literal);
	}
}
