#include "ClapTrap.hpp"

int main() {
    ClapTrap Goku("Goku");

    std::cout << std::endl;
    std::cout << "Set initial attributes..." << std::endl;
    Goku.setHitPoints(2);
    Goku.setEnergyPoints(2);
    Goku.setAttackDamage(0);

    std::cout << std::endl;
    std::cout << "Display initial attributes..." << std::endl;
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << Goku.getAttackDamage() << std::endl << std::endl;

    std::cout << "💣----------FIRST ATTACK!----------------------------💣" << std::endl << std::endl;
    std::cout << "Attempt to attack with initial attack damage points..." << std::endl;
    Goku.attack("Vegeta");
    std::cout << std::endl;
    std::cout << "Display attributes after attacks and damage..." << std::endl;
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << Goku.getAttackDamage() << std::endl;
    std::cout << "Note: As the attack damage point is 0, the attack won't cause any damage." << std::endl << std::endl;

    std::cout << "💣---------SECOND ATTACK!---------------------------💣" << std::endl << std::endl;
    std::cout << "Update attack damage and attempt to attack again..." << std::endl;
    Goku.setAttackDamage(2);
    std::cout << "New attack damage points: " << Goku.getAttackDamage() << std::endl;
    Goku.attack("Vegeta");
    Goku.attack("Vegeta");
    Goku.takeDamage(5);

    std::cout << std::endl;
    std::cout << "Display attributes after attacks and damage..." << std::endl;
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << Goku.getAttackDamage() << std::endl;

    std::cout << std::endl;
    std::cout << "🔧---------ATTEMPT TO REPAIR!-----------------------🔧" << std::endl << std::endl;
    Goku.beRepaired(2);

    std::cout << std::endl;
    std::cout << "Lets give some energy points so " << Goku.getName() << " can repair..." << std::endl;
    Goku.setEnergyPoints(2);
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    Goku.beRepaired(1);
    std::cout << std::endl;
    std::cout << "Ops..." << Goku.getName() << " also need hit points to repair" << std::endl;
    std::cout << "Let's give some hit points..." << std::endl;
    Goku.setHitPoints(1);
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Lets try again..." << std::endl;
    Goku.beRepaired(3);
    std::cout << std::endl;

    return 0;
}
