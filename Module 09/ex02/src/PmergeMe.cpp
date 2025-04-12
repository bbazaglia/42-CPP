#include "PmergeMe.hpp"

#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cmath>

std::size_t PmergeMe::_jacobsthal_cache[62] = {0};

PmergeMe::PmergeMe() : vector_time(0), deque_time(0) {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        original_sequence = other.original_sequence;
        vector = other.vector;
        deque = other.deque;
        vector_time = other.vector_time;
        deque_time = other.deque_time;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parseArguments(int argc, char *argv[])
{
    original_sequence.clear();

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " [positive integers...]" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]);

        for (size_t j = 0; j < arg.length(); ++j)
        {
            if (!std::isdigit(arg[j]))
            {
                std::cerr << "Error: Invalid input '" << arg << "'. Expected a positive integer." << std::endl;
                return false;
            }
        }

        long num = std::atol(arg.c_str());
        if (num > INT_MAX)
        {
            std::cerr << "Error: " << num << " exceeds INT_MAX." << std::endl;
            return false;
        }

        original_sequence.push_back(static_cast<int>(num));
    }

    return true;
}

std::size_t PmergeMe::_calculate_jacobsthal_number(std::size_t n)
{
    if (std::size_t cache = _jacobsthal_cache[n])
        return cache;

    std::size_t result = round((pow(2, n + 1) + pow(-1, n)) / 3);
    _jacobsthal_cache[n] = result;

    return result;
}

// Sort the sequence using both container types
void PmergeMe::sort()
{
    vector = original_sequence;
    deque.assign(original_sequence.begin(), original_sequence.end());

    // Sort with vector and measure time
    clock_t startVector = clock();
    fordJohnsonSort<std::vector<int>, std::vector<std::vector<int>::iterator> >(vector, 1);
    clock_t endVector = clock();
    vector_time = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // µs

    // Sort with deque and measure time
    clock_t startDeque = clock();
    fordJohnsonSort<std::deque<int>, std::deque<std::deque<int>::iterator> >(deque, 1);
    clock_t endDeque = clock();
    deque_time = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; // µs
}

void PmergeMe::displayResults() const
{
    std::cout << "Before: ";
    print_container(original_sequence);

    std::cout << "After: ";
    print_container(vector);
    std::cout << std::endl;

    std::cout << "Time to process a range of " << original_sequence.size()
              << " elements with std::vector : " << vector_time << " us" << std::endl;

    std::cout << "Time to process a range of " << original_sequence.size()
              << " elements with std::deque : " << deque_time << " us" << std::endl;
}
