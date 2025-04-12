#include "PmergeMe.hpp"
#include <iostream>

// test output: ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

int main(int argc, char* argv[]) {
   
    PmergeMe sorter;
 
    if (!sorter.parseArguments(argc, argv))
        return 1;

    sorter.sort();
    
    sorter.displayResults();

    return 0;
}