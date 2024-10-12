#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

public:
    ClapTrap();                           
    ClapTrap(const std::string& name);    
    ClapTrap(const ClapTrap& other);   
    ClapTrap& operator=(const ClapTrap& other); 
    ~ClapTrap();                        

    void setName(const std::string& name);
    void setHitPoints(int hitPoints);
    void setEnergyPoints(int energyPoints);
    void setAttackDamage(int attackDamage);

    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif

/* Orthodox Canonical Form - rule of 5:
    1. Default Constructor
    2. Parameterized Constructor
    3. Copy Constructor
    4. Copy Assignment Operator
    5. Destructor */