#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    ~Dog();

    void makeSound() const;
    Brain   *getBrain(void) const;
    void    setBrain(Brain *brain);

private:
    Brain* _brain;
};

#endif 