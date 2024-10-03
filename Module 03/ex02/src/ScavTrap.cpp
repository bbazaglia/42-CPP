#include "ScavTrap.hpp"

// Constructor
ScavTrap::ScavTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " default constructor called. 🤖" << std::endl;
}

// Parametrized constructor
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " constructor called. 🤖" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << _name << " copy constructor called." << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Calls the base class assignment operator
    }
    std::cout << "ScavTrap copy assigned to " << _name << std::endl;
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " destructor called. 🤖" << std::endl;
}

// Redefine attack method
void ScavTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ScavTrap " << _name << " attacks " << target 
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        --_energyPoints;
    } else {
        std::cout << "ScavTrap " << _name << " can't attack due to "
                  << (_hitPoints <= 0 ? "lack of hit points!" : "lack of energy!") << std::endl;
    }
}

// GuardGate ability
void ScavTrap::guardGate() {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode! 🛡️" << std::endl;
        --_energyPoints;
    } else {
        std::cout << "ScavTrap " << _name << " can't guard the gate due to "
                  << (_hitPoints <= 0 ? "lack of hit points!" : "lack of energy!") << std::endl;
    }
}
