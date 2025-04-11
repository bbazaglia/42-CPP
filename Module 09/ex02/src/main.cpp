#include "PmergeMe.hpp"
#include <iostream>

// test output: ./PmergeMe 11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 7

void testWithRandomNumbers(int count) {
    std::vector<std::string> args;
    args.push_back("PmergeMe"); 

    std::srand(std::time(0)); 
    for (int i = 0; i < count; ++i) {
        args.push_back(std::to_string(std::rand() % 100)); 
    }

    std::cout << "Generated random numbers: ";
    for (size_t i = 1; i < args.size(); ++i) {
        std::cout << args[i] << " ";
    }
    std::cout << std::endl;

    std::vector<char*> argv(args.size());
    for (size_t i = 0; i < args.size(); ++i) {
        argv[i] = &args[i][0];
    }

    PmergeMe sorter;
    sorter.parseArguments(static_cast<int>(argv.size()), argv.data());
    sorter.sort();
    sorter.displayResults();
}

int main(int argc, char* argv[]) {
   
    PmergeMe sorter;

    if (argc == 2 && argv[1] == std::string("test")) {
        testWithRandomNumbers(20); 
    }
    else {
        sorter.parseArguments(argc, argv);
        sorter.sort();
        sorter.displayResults();
    }
    
    return 0;
}