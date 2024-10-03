#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
public:
    // Default constructor
    ScavTrap();
    
    // Parametrized constructor
    ScavTrap(const std::string& name);
    
    // Copy constructor
    ScavTrap(const ScavTrap& other);
    
    // Copy assignment operator
    ScavTrap& operator=(const ScavTrap& other);
    
    // Destructor
    ~ScavTrap();

    // Override attack method
    void attack(const std::string& target);

    // Special ability
    void guardGate();
};

#endif
