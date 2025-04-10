#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
   
    PmergeMe sorter;

    sorter.parseArguments(argc, argv);
    sorter.sort();
    sorter.displayResults();

    return 0;
}