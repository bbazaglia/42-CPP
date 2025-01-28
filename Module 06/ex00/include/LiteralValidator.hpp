#ifndef LITERALVALIDATOR_HPP
# define LITERALVALIDATOR_HPP

# include <cctype>
# include <cerrno>
# include <cstdlib>
# include <limits>
# include <sstream>

bool	isCharLiteral(const std::string &input);
bool	isIntLiteral(const std::string &input);
bool	isFloatLiteral(const std::string &input);
bool	isDoubleLiteral(const std::string &input);

#endif
