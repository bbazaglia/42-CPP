#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
    std::cout << "Testing with default Animal constructors... 🛠️" << std::endl;

    /* cannot instantiate abstract class
    const Animal *meta = new Animal();
    std::cout << meta->getType() << ": ";
    meta->makeSound();
    std::cout << std::endl;*/

    const Animal *puppie = new Dog();
    std::cout << puppie->getType() << ": ";
    puppie->makeSound();
    std::cout << std::endl;

    const Animal *kitty = new Cat();
    std::cout << kitty->getType() << ": ";
    kitty->makeSound(); 
    std::cout << std::endl;

    const WrongAnimal* maggie = new WrongAnimal();
    std::cout << maggie->getType() << ": ";
    maggie->makeSound();
    std::cout << std::endl;

    const WrongAnimal* tom = new WrongCat();
    std::cout << tom->getType() << ": ";
    tom->makeSound();
    std::cout << std::endl;

    std::cout << "Testing with copy constructor... 🔨" << std::endl;
    Dog *doggie = new Dog();
    Dog luke = *doggie;
    std::cout << "Type: " << luke.getType() << std::endl;
    luke.makeSound();
    std::cout << std::endl; 

    std::cout << "Testing with assignment operator... 🔧" << std::endl;
    Cat *garfield = new Cat();
    Cat felix;
    felix = *garfield;
    std::cout << "Type: " << felix.getType() << std::endl;
    felix.makeSound();
    std::cout << std::endl; 

    std::cout << "Testing with copy constructor for Cat... 🔨" << std::endl;
    Cat copyCat = *garfield;
    std::cout << "Type: " << copyCat.getType() << std::endl;
    copyCat.makeSound();
    std::cout << std::endl; 

    std::cout << "Testing with assignment operator for Dog... 🔧" << std::endl;
    Dog *anotherDog = new Dog();
    luke = *anotherDog;
    std::cout << "Type: " << luke.getType() << std::endl;
    luke.makeSound();
    std::cout << std::endl; 

    std::cout << "Calling destructors 💣" << std::endl;

    delete puppie;
    delete kitty;
    delete tom;
    delete maggie;
    delete doggie;
    delete garfield;
    delete anotherDog;

    return (0);
}


// int main() {
//     Brain original;
//     original.setIdea(0, "Original idea 1");
//     original.setIdea(1, "Original idea 2");

//     Brain copy(original); // Calls the copy constructor

//     std::cout << "Original ideas:" << std::endl;
//     std::cout << "Idea 0: " << original.getIdea(0) << std::endl;
//     std::cout << "Idea 1: " << original.getIdea(1) << std::endl;

//     std::cout << "Copy ideas:" << std::endl;
//     std::cout << "Idea 0: " << copy.getIdea(0) << std::endl;
//     std::cout << "Idea 1: " << copy.getIdea(1) << std::endl;

//     // Modify the copy's ideas
//     copy.setIdea(0, "Modified idea 1");
//     copy.setIdea(1, "Modified idea 2");

//     std::cout << "After modifying the copy:" << std::endl;
//     std::cout << "Original ideas:" << std::endl;
//     std::cout << "Idea 0: " << original.getIdea(0) << std::endl;
//     std::cout << "Idea 1: " << original.getIdea(1) << std::endl;

//     std::cout << "Copy ideas:" << std::endl;
//     std::cout << "Idea 0: " << copy.getIdea(0) << std::endl;
//     std::cout << "Idea 1: " << copy.getIdea(1) << std::endl;

//     return 0;
// }

