#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

/* 
**Base Class**: The class whose properties and methods are inherited.
**Derived Class**: The class that inherits from the base class.

Public Inheritance:
Public members of the base class remain public in the derived class.
Protected members of the base class remain protected in the derived class.
Private members of the base class are not accessible in the derived class directly.

Constructor and Destructor Order:
**Constructor**: Base class constructor is called before the derived class constructor.
**Destructor**: Derived class destructor is called before the base class destructor.*/

class ScavTrap : public ClapTrap {
public:
    ScavTrap()
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap& other);
    ScavTrap& operator=(const ScavTrap& other);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif 