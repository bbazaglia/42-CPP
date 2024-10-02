#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default ClapTrap constructor called. 👋" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructor called. 👋" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy " << _name << " constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap copy assignment operator called." << std::endl;
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructor called. 👋" << std::endl;
}

// getters
std::string ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }

// setters
void ClapTrap::setName(const std::string& name) { 
    std::cout << "ClapTrap name was " << _name << std::endl;
    _name = name; 
    std::cout << "ClapTrap new name is " << _name << std::endl;
}

void ClapTrap::setHitPoints(int hitPoints) { 
    std::cout << "ClapTrap " << _name << " hit points were " << _hitPoints << std::endl;
    _hitPoints = hitPoints; 
    std::cout << "ClapTrap " << _name << " hit points are now " << _hitPoints << std::endl;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
    std::cout << "ClapTrap " << _name << " energy points were " << _energyPoints << std::endl;
    _energyPoints = energyPoints; 
    std::cout << "ClapTrap " << _name << " energy points are now " << _energyPoints << std::endl; 
}

void ClapTrap::setAttackDamage(int attackDamage) { 
    std::cout << "ClapTrap " << _name << " attack damage was " << _attackDamage << std::endl;
    _attackDamage = attackDamage; 
    std::cout << "ClapTrap " << _name << " attack damage is now " << _attackDamage << std::endl;   
}


// decrease the ClapTrap's energy points by 1 and attack the target
void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                  << _attackDamage << " points of damage!" << std::endl;
        --_energyPoints;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack because "
                  << (_hitPoints <= 0 ? "it has no hit points left!" : 
                      (_energyPoints <= 0 ? "it has no energy points left!" : "")) 
                  << std::endl;
    }
}

// decrease the ClapTrap's hit points by the amount of damage it takes
void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        if (_hitPoints < 0) 
            _hitPoints = 0;
        std::cout << _name << " took " << amount << " points of damage! Remaining hit points: "
                  << _hitPoints << std::endl;
    } else {
        std::cout << _name << " is already out of hit points!" << std::endl;
    }
}

// increase the ClapTrap's hit points by the amount of healing it receives
void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0 && _energyPoints > 0) {
        _hitPoints += amount;
        --_energyPoints;
        std::cout << _name << " repairs itself, recovering " << amount << " hit points! Remaining hit points: " 
                  << _hitPoints << ", energy points: " << _energyPoints << std::endl;
    } else {
        std::cout << "ClapTrap " << _name << " can't repair because it has no "
                  << (_hitPoints <= 0 ? "hit points" : "energy points") << " left!" << std::endl;
    }
}
