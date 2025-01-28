#include "Functions.hpp"

// Randomly generate an instance of A, B, or C
Base* generate(void) {
    static bool first = true;
     if (first) {             // First time running? Then seed the random generator
        srand(time(NULL));    // Use current time as seed for random numbers
        first = false;        // Never seed again
    }
    
    
    int random = rand() % 3; // Generate random number between 0 and 2
    
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return NULL;
    }
}

// Identify type using pointer
void identify(Base* p) {
    // Try to cast to each type. Only one will succeed.
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else {
		std::cout << "Unknown class" << std::endl;
	}
}

// Identify type using reference
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
}
