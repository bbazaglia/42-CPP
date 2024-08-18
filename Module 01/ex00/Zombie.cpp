#include "Zombie.hpp"

/*
 * The initializer list directly initializes the member variable "name" with the parameter "name".
 * The syntax ": name(name)" is unambiguous, so there's no need to use "this->".
 * The first "name" refers to the class's member variable, while the second refers to the constructor's parameter. 
 * This method is more efficient because the member variable is initialized only once.
 */
Zombie::Zombie(std::string name) : name(name) {
    std::cout << name << " is constructed." << std::endl;
}

/*
 * Alternatively, you could initialize the member variable inside the constructor body:
 * 
 * Zombie::Zombie(std::string name) {
 *     this->name = name;
 * }
 * 
 * In this case, "this->" is necessary to explicitly refer to the member variable "name" of the current instance,
 * as both the parameter and the member variable share the same name. 
 * This method is less efficient because the member variable is first default-initialized and 
 * then assigned a new value, which involves an extra step compared to using an initializer list.
 */

Zombie::~Zombie()
{
	std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}