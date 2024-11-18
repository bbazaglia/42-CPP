#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
    Animal();
    Animal(const Animal& copy);
    Animal& operator=(const Animal& copy);
    virtual ~Animal();

    std::string getType() const;
    virtual void makeSound() const;

protected:
    std::string _type;
};

#endif 