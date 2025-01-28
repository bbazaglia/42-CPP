#include "Functions.hpp"

int main() {
    for (int i = 0; i < 5; i++) {
        Base* ptr = generate();
        
        std::cout << "Using pointer: ";
        identify(ptr);
        
        std::cout << "Using reference: ";
        identify(*ptr);
        
        std::cout << "-------------------" << std::endl;
        
        delete ptr; 
    }
    
    return 0;
}