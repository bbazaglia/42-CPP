#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>

class PmergeMe {
private:
    std::vector<int> m_originalSequence;
    std::vector<int> m_vectorSorted;
    std::deque<int> m_dequeSorted;
    double m_vectorTime;
    double m_dequeTime;

    bool isPositiveInteger(const std::string& str) const;
    void fordJohnsonSortVector(std::vector<int>& arr, int depth = 0);
    void fordJohnsonSortDeque(std::deque<int>& deq);

public:
    PmergeMe(); 
    PmergeMe(const PmergeMe &other);
    PmergeMe & operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArguments(int argc, char* argv[]);
    void sort();
    void displayResults() const;

    // Getters
    const std::vector<int>& getOriginalSequence() const;
    const std::vector<int>& getVectorSorted() const;
    const std::deque<int>& getDequeSorted() const;
    double getVectorTime() const;
    double getDequeTime() const;
};

#endif // PMERGE_ME_HPP