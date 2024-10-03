#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
    // Default constructor
    FragTrap();
    
    // Parametrized constructor
    FragTrap(const std::string& name);
    
    // Copy constructor
    FragTrap(const FragTrap& other);
    
    // Copy assignment operator
    FragTrap& operator=(const FragTrap& other);
    
    // Destructor
    ~FragTrap();

    // Override attack method
    void attack(const std::string& target);

    // Special ability
    void highFivesGuys();
};

#endif
