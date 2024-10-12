#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);

    /* virtual destructor ensures that when an object is deleted through a pointer to the base class, 
    the destructor of the derived class will be called first, followed by the base class destructor.*/
    virtual ~Animal();

    // dynamic dispatch: the correct version of the function will be called depending on the actual type of the object
    virtual makeSound() const;

protected:
    std::string type;
};

#endif 