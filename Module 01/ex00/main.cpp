#include "Zombie.hpp"

int main() {
    std::cout << "🧟 Zombies in the stack: 🧟" << std::endl;
    randomChump("Alice");
    randomChump("Cheshire Cat");

    std::cout << std::endl;

    std::cout << "🧟 Zombies in the heap: 🧟" << std::endl;
    Zombie* whiteRabbit = newZombie("White Rabbit");
    whiteRabbit->announce();
    delete whiteRabbit;
    Zombie* madHatter = newZombie("Mad Hatter");
    madHatter->announce();
    delete madHatter;
}