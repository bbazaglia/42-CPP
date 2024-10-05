#include "ClapTrap.hpp"

int main() {

    ClapTrap harry;
    harry.setName("Harry");
    std::cout << "Let's name him " << harry.getName() << std::endl;
    std::cout << "\033[34mNow, let's display his default attributes\033[0m" << std::endl;
    std::cout << "Hit Points: " << harry.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << harry.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << harry.getAttackDamage() << std::endl;
    std::cout << "\033[34mShould we set some different values?\033[0m" << std::endl;
    harry.setHitPoints(3);
    harry.setEnergyPoints(10);
    harry.setAttackDamage(8);
    std::cout << "Hit Points: " << harry.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << harry.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << harry.getAttackDamage() << std::endl;
    std::cout << std::endl;

    ClapTrap ron("Ron");
    std::cout << "\033[34mNow, let's display his default attributes\033[0m" << std::endl;
    std::cout << "Hit Points: " << ron.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << ron.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << ron.getAttackDamage() << std::endl;
    std::cout << std::endl;

    std::cout << "Let's create a copy of Hermione using " << ron.getName() << std::endl;
    ClapTrap hermione(ron);
    std::cout << "\033[34mNow, let's display her default attributes\033[0m" << std::endl;
    std::cout << "Hit Points: " << ron.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << ron.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << ron.getAttackDamage() << std::endl;
    std::cout << "\033[34mAlthough she dates Ron, her values are more close to Harry's\033[0m" << std::endl;
    hermione.operator=(harry);
    hermione.setName("Hermione");
    std::cout << "\033[34mNow, let's display her new attributes\033[0m" << std::endl;
    std::cout << "Hit Points: " << hermione.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << hermione.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage Points: " << hermione.getAttackDamage() << std::endl;
    std::cout << std::endl;


    std::cout << "Let's not forget to construct their bigget enemy" << std::endl;
    ClapTrap draco("Draco");
    draco.setAttackDamage(3);
    std::cout << std::endl;

    std::cout << "💣------------- ATTACK!--------------------------------------💣" << std::endl << std::endl;
    draco.attack("Harry");
    draco.getEnergyPoints();
    harry.takeDamage(draco.getAttackDamage());
    harry.attack("Draco");
    harry.beRepaired(20);
    std::cout << harry.getName() << " is useless. Lets have our day saved by a girl." << std::endl;
    hermione.attack("Draco");
    std::cout << hermione.getName() << " new amount of energy points is " << hermione.getEnergyPoints() << std::endl;
    std::cout << "Fighting really repairs her spirit!" << std::endl;
    hermione.beRepaired(10);
    draco.takeDamage(hermione.getAttackDamage());
    std::cout << std::endl;

    return 0;
}
