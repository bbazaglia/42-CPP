#include "Zombie.hpp"

// This function uses stack allocation to create a Zombie object.
// The Zombie is automatically destroyed when the function exits,
// making it ideal for short-lived objects that don't need to persist.
void randomChump(std::string name) {
    Zombie zombie(name);
    zombie.announce();
}
