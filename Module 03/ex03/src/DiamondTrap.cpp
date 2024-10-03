#include "DiamondTrap.hpp"

/*
The diamond problem occurs when a class inherits from two classes that both inherit from a common base class. This can lead to ambiguity and multiple copies of the base class.
Virtual Inheritance: This ensures that only one instance of the base class (ClapTrap) is shared among all derived classes (FragTrap and ScavTrap), preventing multiple copies of the base class.
Constructor Initialization: When you initialize DiamondTrap, it will correctly initialize the single instance of ClapTrap.
*/

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap(), _name("") {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " default constructor called. 💎" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " constructor called. 💎" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other._name + "_clap_name"), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap " << _name << " copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        _name = other._name;
    }
    std::cout << "DiamondTrap copy assigned to " << _name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called. 💎" << std::endl;
}

void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

std::string DiamondTrap::getName() const {
    return _name;
}

void DiamondTrap::setName(const std::string& name) {
    _name = name;
}