#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

/* Since WrongAnimal has no virtual functions, all member functions are statically bound. 
   Calling makeSound() on a WrongAnimal* pointing to a WrongCat will invoke WrongAnimal's version unless overridden in WrongCat. 
   Even if overridden, it won't exhibit polymorphic behavior due to the absence of virtual mechanisms. */

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& copy);
    WrongAnimal& operator=(const WrongAnimal& copy);
    ~WrongAnimal();

    void makeSound() const;
    std::string getType() const;

protected:
    std::string _type;
};

#endif 