#include "Zombie.hpp"

// This function uses heap allocation to create a Zombie object.
// The Zombie persists beyond the function's scope and must be manually
// deleted by the caller, making it suitable for objects with a longer lifespan.
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}



