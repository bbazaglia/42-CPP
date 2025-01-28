#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include "A.hpp"
# include "B.hpp"
# include "Base.hpp"
# include "C.hpp"
# include <cstdlib>
# include <ctime>
# include <exception>
# include <iostream>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif