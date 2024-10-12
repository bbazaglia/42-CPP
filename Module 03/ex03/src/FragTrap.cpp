#include "FragTrap.hpp"

// Constructor
FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " default constructor called." << std::endl;
}

// Parametrized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructor called." << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << _name << " copy constructor called." << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);  // Calls the base class assignment operator
    }
    std::cout << "FragTrap copy assigned to " << _name << std::endl;
    return *this;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _name << " destructor called." << std::endl;
}

// HighFivesGuys ability
void FragTrap::highFivesGuys() {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "FragTrap " << _name << " is giving high fives to everyone! 🖐️" << std::endl;
        --_energyPoints;
    } else {
        std::cout << "FragTrap " << _name << " can't give high fives due to "
                  << (_hitPoints <= 0 ? "lack of hit points!" : "lack of energy!") << std::endl;
    }
}
