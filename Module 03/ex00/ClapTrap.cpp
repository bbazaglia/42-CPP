#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "Default ClapTrap constructor called. 👋" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " constructor called. 👋" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
    std::cout << "ClapTrap copy constructor called." << std::endl;
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
    std::cout << "ClapTrap destructor called. 👋" << std::endl;
}

void ClapTrap::setName(const std::string& name) { _name = name; }
void ClapTrap::setHitPoints(int hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(int energyPoints) { _energyPoints = energyPoints; }
void ClapTrap::setAttackDamage(int attackDamage) { _attackDamage = attackDamage; }

std::string ClapTrap::getName() const { return _name; }
int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }


void ClapTrap::attack(const std::string& target) {
    if (_hitPoints > 0 && _energyPoints > 0 && _attackDamage > 0) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                  << _attackDamage << " points of damage!" << std::endl;
        --_energyPoints;
    } else {
        std::cout << "ClapTrap " << _name << " can't attack because "
                  << (_hitPoints <= 0 ? "it has no hit points left!" :
                      _energyPoints <= 0 ? "it has no energy points left!" :
                      "attack damage can't be negative or zero!") << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        if (_hitPoints < 0) _hitPoints = 0;
        std::cout << _name << " took " << amount << " points of damage! Remaining hit points: "
                  << _hitPoints << std::endl;
    } else {
        std::cout << _name << " is already out of hit points!" << std::endl;
    }
}

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
