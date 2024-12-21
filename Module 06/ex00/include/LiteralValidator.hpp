#ifndef LITERALVALIDATOR_HPP
#define LITERALVALIDATOR_HPP

#include <sstream>
#include <cctype> 
#include <limits>  
#include <cerrno>
# include <cstdlib>


class LiteralValidator {
public:
    static bool isCharLiteral(const std::string &input);
    static bool isIntLiteral(const std::string &input);
    static bool isFloatLiteral(const std::string &input);
    static bool isDoubleLiteral(const std::string &input);
};

#endif
