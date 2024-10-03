#include "DiamondTrap.hpp"

int main() {
    // Create a DiamondTrap instance using the default constructor
    DiamondTrap buzz;
    buzz.setName("Lightyear");
    std::cout << std::endl << "DiamondTrap 1 Name: " << buzz.getName() << std::endl;
    buzz.whoAmI();

    // Create a DiamondTrap instance using the parameterized constructor
    DiamondTrap woody("Sheriff");
    std::cout << std::endl << "DiamondTrap 2 Name: " << woody.getName() << std::endl;
    woody.whoAmI();

    // Create a DiamondTrap instance using the copy constructor
    DiamondTrap Jess(woody);
    std::cout << std::endl << "DiamondTrap 3 Name (copied from woody): " << Jess.getName() << std::endl;
    Jess.whoAmI();

    // Use the assignment operator
    buzz = woody;
    std::cout << std::endl << "DiamondTrap 1 Name (after assignment from woody): " << buzz.getName() << std::endl;
    buzz.whoAmI();

    std::cout << std::endl;
}