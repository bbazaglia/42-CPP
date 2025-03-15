#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN [inverted Polish mathematical expression]" << std::endl;
        return 1;
    }

    /* Using a stack as our container:
        LIFO (Last-In-First-Out) matches how RPN operators work on recent operands
        Naturally handles the sequential processing of the expression */

} 