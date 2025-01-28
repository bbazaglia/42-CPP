#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "LiteralValidator.hpp"
# include "SafeConverter.hpp"
# include <cstdlib>
# include <iostream>
# include <string>

class ScalarConverter
{
  private:
	ScalarConverter(); // Private constructor to prevent instantiation
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

  public:
	~ScalarConverter();
	static void convert(const std::string &input);
};

#endif
