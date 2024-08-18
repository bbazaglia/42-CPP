#include "Zombie.hpp"

int main(void) {

    int N = 5;
    std::string name = "Stormtrooper";
    Zombie *zombies;
    
    std::cout << "🧟 Calling the " << name << " zombieHorde of " << N << " zombies. 🧟" << std::endl;
    zombies = zombieHorde(N, name);

    std::cout << "🧟 What the zombie says? 🧟" << std::endl;
    for(int i = 0; i < N; i++)
        zombies[i].announce();

    std::cout << "🧟 So long, zombies! 🧟" << std::endl;
    delete [] zombies;

}