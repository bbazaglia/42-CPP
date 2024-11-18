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

    std::string getType() const;
    // dynamic dispatch: the correct version of the function will be called depending on the actual type of the object
    virtual void makeSound() const;

protected:
    // derive classes can directly access _type without needing a public setter
    std::string _type;
};

/* 
 * Base class: any class that other classes inherit from. 
   It can have implemented methods and virtual methods.

   - virtual methods are declared with the syntax: virtual void makeSound() const;
    they can be overridden by derived classes.

 * Interface: type of base class that has only pure virtual functions. 
   It is used to define a protocol of methods that derived classes must implement.

   - pure virtual functions do not have an implementation in the base class.
    they are declared with the syntax: virtual void makeSound() const = 0;

 * Abstract class: classes with pure virtual functions and cannot be instantiated directly.

 * Concrete class: classes that provides implementations for all its methods and can be instantiated directly.

 * Polymorphism: the ability to present the same interface for different data types.
   It is achieved by using inheritance and virtual functions.
*/

#endif 