#include "whatever.hpp"

int	main(void)
{
	// Example usage with integers
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	 std::cout << "-------------------" << std::endl;

	// Example usage with strings
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << "-------------------" << std::endl;

	// Example usage with different strings
	std::string str1 = "baaa";
	std::string str2 = "abbbb";
	::swap(str1, str2);
	std::cout << "str1 = " << str1 << ", str2 = " << str2 << std::endl;
	std::cout << "min( str1, str2 ) = " << ::min(str1, str2) << std::endl;
	std::cout << "max( str1, str2 ) = " << ::max(str1, str2) << std::endl;
	std::cout << "-------------------" << std::endl;

	// Example usage with doubles
    double e = 3.14;
	double f = 2.71;
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << max(e, f) << std::endl;

	return (0);
}