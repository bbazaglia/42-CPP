#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating ScavTrap instances:" << std::endl;
    ScavTrap Harry("Harry");
    std::cout << std::endl;
    ScavTrap Ron("Ron");
    std::cout << std::endl;
    ScavTrap Hermione("Hermione");
    std::cout << std::endl;
    ScavTrap HermioneCopy(Hermione);
    std::cout << std::endl;
    ScavTrap Hagrid;
    Hagrid = Ron;
    std::cout <<  "Change the name of the copy assigned to Ron to Hagrid..." << std::endl;
    Hagrid.setName("Hagrid");

    std::cout << std::endl << "Values before assignment:" << std::endl;
    std::cout << Harry.getName() << " has " << Harry.getHitPoints() << " hit points, " << Harry.getEnergyPoints() << " energy points and " << Harry.getAttackDamage() << " points of attack damage." << std::endl;
    std::cout << Ron.getName() << " has " << Ron.getHitPoints() << " hit points, " << Ron.getEnergyPoints() << " energy points and " << Ron.getAttackDamage() << " points of attack damage." << std::endl;
    std::cout << Hermione.getName() << " has " << Hermione.getHitPoints() << " hit points, " << Hermione.getEnergyPoints() << " energy points and " << Hermione.getAttackDamage() << " points of attack damage." << std::endl;
    std::cout << HermioneCopy.getName() << " copy has " << HermioneCopy.getHitPoints() << " hit points, " << HermioneCopy.getEnergyPoints() << " energy points and " << HermioneCopy.getAttackDamage() << " points of attack damage." << std::endl;
    std::cout << Hagrid.getName() << " has " << Hagrid.getHitPoints() << " hit points, " << Hagrid.getEnergyPoints() << " energy points and " << Hagrid.getAttackDamage() << " points of attack damage." << std::endl;

    std::cout << std::endl << "Setting new values to " <<  Harry.getName() << " and the copy of " << HermioneCopy.getName()  << "..." << std::endl;
    Harry.setName("Harry Potter");
    Harry.setHitPoints(13);
    Harry.setEnergyPoints(15);
    Harry.setAttackDamage(3);
    std::cout << std::endl;
    HermioneCopy.setName("Hermione Granger");
    HermioneCopy.setHitPoints(0);
    HermioneCopy.setEnergyPoints(1);
    HermioneCopy.setAttackDamage(5);
    
    std::cout << std::endl << "Let's start the attacks..." << std::endl;
    Harry.attack("Voldemort");
    Harry.guardGate();
    HermioneCopy.guardGate();
    HermioneCopy.setHitPoints(1);
    HermioneCopy.attack("Bellatrix");
    HermioneCopy.attack("Draco");
    std::cout << std::endl;

    return 0;
}
