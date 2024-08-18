#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " is constructed." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}