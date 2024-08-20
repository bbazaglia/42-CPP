#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARNING|ERROR>" << std::endl;
        return 1;
    }

    std::string level = argv[1];
    Harl harl;

    std::cout << "Complaining at level: " << level << std::endl;
    harl.filter(level);

    return 0;
}
