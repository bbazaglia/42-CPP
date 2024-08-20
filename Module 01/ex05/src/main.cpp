#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Test 1: DEBUG level" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nTest 2: INFO level" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\nTest 3: WARNING level" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\nTest 4: ERROR level" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\nTest 5: UNKNOWN level" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}
