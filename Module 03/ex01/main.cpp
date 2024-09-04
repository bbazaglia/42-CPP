#include "ClapTrap.hpp"

int main() {
    ClapTrap Goku;

    std::cout << "Set initial attributes..." << std::endl;
    Goku.setName("Goku");
    Goku.setHitPoints(2);
    Goku.setEnergyPoints(2);
    Goku.setAttackDamage(0);

    std::cout << "\nDisplay initial attributes..." << std::endl;
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << Goku.getAttackDamage() << std::endl;

    std::cout << "\nAttempt to attack with initial attack damage points..." << std::endl;
    Goku.attack("Vegeta");

    std::cout << "\nUpdate attack damage and attempt to attack again..." << std::endl;
    Goku.setAttackDamage(2);
    std::cout << "New attack damage points: " << Goku.getAttackDamage() << std::endl;
    Goku.attack("Vegeta");
    Goku.attack("Vegeta");
    Goku.attack("Vegeta");
    Goku.takeDamage(5);

    std::cout << "\nAttempt to repair..." << std::endl;
    Goku.beRepaired(2);

    std::cout << "\nDisplay attributes after attacks and damage..." << std::endl;
    std::cout << "Hit Points: " << Goku.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << Goku.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << Goku.getAttackDamage() << std::endl;
    return 0;
}
