#include "PmergeMe.hpp"

#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>

PmergeMe::PmergeMe() : m_vectorTime(0), m_dequeTime(0) {}

PmergeMe::~PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
    : m_originalSequence(other.m_originalSequence),
      m_vectorSorted(other.m_vectorSorted),
      m_dequeSorted(other.m_dequeSorted),
      m_vectorTime(other.m_vectorTime),
      m_dequeTime(other.m_dequeTime) {}

// Assignment operator
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        m_originalSequence = other.m_originalSequence;
        m_vectorSorted = other.m_vectorSorted;
        m_dequeSorted = other.m_dequeSorted;
        m_vectorTime = other.m_vectorTime;
        m_dequeTime = other.m_dequeTime;
    }
    return *this;
}

bool PmergeMe::isPositiveInteger(const std::string &str) const {
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool PmergeMe::parseArguments(int argc, char *argv[]) {
    m_originalSequence.clear();

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);

        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        long num = atol(arg.c_str());
        if (num > INT_MAX || num < 0) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        m_originalSequence.push_back(static_cast<int>(num));
    }

    if (m_originalSequence.empty()) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    return true;
}

// Generate Jacobsthal numbers up to n
std::vector<size_t> PmergeMe::generateJacobsthalNumbers(size_t n) const {
    std::vector<size_t> jacobsthal;

    if (n == 0)
        return jacobsthal;

    // Start with the first two Jacobsthal numbers
    jacobsthal.push_back(0);
    if (n == 1)
        return jacobsthal;

    jacobsthal.push_back(1);

    // Generate Jacobsthal numbers until we exceed n
    size_t i = 2;
    while (true) {
        size_t next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        if (next > n)
            break;

        jacobsthal.push_back(next);
        i++;
    }

    return jacobsthal;
}

// Get insertion sequence based on Jacobsthal numbers
std::vector<size_t> PmergeMe::getInsertionSequence(size_t n) const {
    if (n == 0)
        return std::vector<size_t>();

    std::vector<size_t> jacobsthal = generateJacobsthalNumbers(n);
    std::vector<size_t> sequence;

    // Handle the case of a single element separately
    if (n == 1) {
        sequence.push_back(1);
        return sequence;
    }

    // Create a sequence based on Jacobsthal numbers
    // Skip 0, we start with element at index 1
    for (size_t i = 1; i < jacobsthal.size(); i++) {
        size_t current = jacobsthal[i];

        // Add the current Jacobsthal number
        if (current <= n)
            sequence.push_back(current);

        // Add numbers between this and the previous Jacobsthal number in reverse
        for (size_t j = current - 1; j > jacobsthal[i - 1]; j--) {
            if (j <= n)
                sequence.push_back(j);
        }
    }

    // Add any remaining numbers in sequence
    size_t last = jacobsthal.back();
    for (size_t i = last + 1; i <= n; i++) {
        sequence.push_back(i);
    }

    return sequence;
}

// Sort the sequence using both container types
void PmergeMe::sort() {
    m_vectorSorted = m_originalSequence;
    m_dequeSorted.assign(m_originalSequence.begin(), m_originalSequence.end());

    // Sort with vector and measure time
    clock_t startVector = clock();
    fordJohnsonSort(m_vectorSorted);
    clock_t endVector = clock();
    m_vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // µs

    // Sort with deque and measure time
    clock_t startDeque = clock();
    fordJohnsonSort(m_dequeSorted);
    clock_t endDeque = clock();
    m_dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; // µs
}

void PmergeMe::displayResults() const {
    std::cout << "Before: ";
    for (size_t i = 0; i < m_originalSequence.size(); i++) {
        std::cout << m_originalSequence[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for (size_t i = 0; i < m_vectorSorted.size(); i++) {
        std::cout << m_vectorSorted[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << m_originalSequence.size()
              << " elements with std::vector : " << m_vectorTime << " us" << std::endl;

    std::cout << "Time to process a range of " << m_originalSequence.size()
              << " elements with std::deque : " << m_dequeTime << " us" << std::endl;
}

// Getters
const std::vector<int> &PmergeMe::getOriginalSequence() const {
    return m_originalSequence;
}

const std::vector<int> &PmergeMe::getVectorSorted() const {
    return m_vectorSorted;
}

const std::deque<int> &PmergeMe::getDequeSorted() const {
    return m_dequeSorted;
}

double PmergeMe::getVectorTime() const {
    return m_vectorTime;
}

double PmergeMe::getDequeTime() const {
    return m_dequeTime;
}