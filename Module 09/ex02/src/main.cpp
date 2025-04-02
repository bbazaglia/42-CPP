#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [positive integers...]" << std::endl;
        return 1;
    }
    
    PmergeMe sorter;
    
    if (!sorter.parseArguments(argc, argv)) {
        return 1;
    }
    
    sorter.sort();
    sorter.displayResults();
    
    return 0;
}