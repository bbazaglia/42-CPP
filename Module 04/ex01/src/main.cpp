#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // Fill the array with Dog and Cat objects
    for (int i = 0; i < numAnimals / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = numAnimals / 2; i < numAnimals; ++i) {
        animals[i] = new Cat();
    }

    // Loop over the array and delete each Animal
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    // Check if copies of Dog and Cat are not shallow
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Original Dog Idea 1");
    originalDog.getBrain()->setIdea(1, "Original Dog Idea 2");

    Dog copiedDog(originalDog); // Copy constructor
    std::cout << "Copied Dog Brain Idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea 1: " << copiedDog.getBrain()->getIdea(1) << std::endl;

    originalDog.getBrain()->setIdea(0, "Modified Dog Idea 1");
    std::cout << "Original Dog Brain Idea 0 after modification: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog Brain Idea 0 after original modification: " << copiedDog.getBrain()->getIdea(0) << std::endl;

    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Original Cat Idea 1");
    originalCat.getBrain()->setIdea(1, "Original Cat Idea 2");

    Cat copiedCat(originalCat); // Copy constructor
    std::cout << "Copied Cat Brain Idea 0: " << copiedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat Brain Idea 1: " << copiedCat.getBrain()->getIdea(1) << std::endl;

    originalCat.getBrain()->setIdea(0, "Modified Cat Idea 1");
    std::cout << "Original Cat Brain Idea 0 after modification: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat Brain Idea 0 after original modification: " << copiedCat.getBrain()->getIdea(0) << std::endl;

    // Check assignment operator
    Dog assignedDog;
    assignedDog = originalDog;
    std::cout << "Assigned Dog Brain Idea 0: " << assignedDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Dog Brain Idea 1: " << assignedDog.getBrain()->getIdea(1) << std::endl;

    originalDog.getBrain()->setIdea(0, "Another Modified Dog Idea 1");
    std::cout << "Original Dog Brain Idea 0 after another modification: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Dog Brain Idea 0 after original modification: " << assignedDog.getBrain()->getIdea(0) << std::endl;

    Cat assignedCat;
    assignedCat = originalCat;
    std::cout << "Assigned Cat Brain Idea 0: " << assignedCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat Brain Idea 1: " << assignedCat.getBrain()->getIdea(1) << std::endl;

    originalCat.getBrain()->setIdea(0, "Another Modified Cat Idea 1");
    std::cout << "Original Cat Brain Idea 0 after another modification: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Assigned Cat Brain Idea 0 after original modification: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    return 0;
}