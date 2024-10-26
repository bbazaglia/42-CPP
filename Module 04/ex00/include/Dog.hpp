#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

//  The Dog class inherits the virtual function behavior from Animal, so it doesn’t need to redeclare makeSound() or any other function as virtual again
class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    ~Dog();
    void makeSound() const;
};

#endif 