#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

public:
    Harl();
    ~Harl();

    void complain(std::string level);
};

/* 
 * syntax for declaring a pointer to a member function: 
 * return_type (ClassName::*pointer_name)(parameter_list); 
 * 
 * to assign a member function to a pointer, use the address-of operator (&):
 * pointer_name = &ClassName::member_function_name;
 * 
 * to call a member function using a pointer, use the pointer-to-member operator (.*):
 * (object.*pointer_name)(arguments);
*/

#endif