#include "FragTrap.hpp"

int main() {
    FragTrap fragTrap("Fraggy");
    ScavTrap scavTrap("Scavvy");

    fragTrap.attack("Scavvy");
    scavTrap.attack("Fraggy");

    fragTrap.highFivesGuys();
    scavTrap.guardGate();

    return 0;
}