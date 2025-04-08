#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> m_originalSequence;
    std::vector<int> m_vectorSorted;
    std::deque<int> m_dequeSorted;
    double m_vectorTime;
    double m_dequeTime;

    bool isPositiveInteger(const std::string &str) const;
    std::vector<size_t> generateJacobsthalNumbers(size_t n) const;
    std::vector<size_t> getInsertionSequence(size_t n) const;
    
    template <typename Container>
    void fordJohnsonSort(Container &container);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    bool parseArguments(int argc, char *argv[]);
    void sort();
    void displayResults() const;

    // Getters
    const std::vector<int> &getOriginalSequence() const;
    const std::vector<int> &getVectorSorted() const;
    const std::deque<int> &getDequeSorted() const;
    double getVectorTime() const;
    double getDequeTime() const;
};

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &arr) {
    const size_t size = arr.size();
    if (size <= 1)
        return;

    // Step 1: Make pairs and sort them internally
    std::vector<std::pair<int, int> > pairs;
    bool isOdd = (size % 2 != 0);
    int oddNum = 0;

    if (isOdd) {
        oddNum = arr[size - 1];
    }

    // Create pairs and ensure smaller is first, larger is second
    for (size_t i = 0; i < size - isOdd; i += 2) {
        int first = arr[i];
        int second = arr[i + 1];
        if (first > second)
            std::swap(first, second);
        pairs.push_back(std::make_pair(first, second));
    }

    // Step 2: Extract larger elements for recursive sorting
    Container largerElements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        largerElements.push_back(pairs[i].second);
    }

    // Recursively sort the larger elements
    fordJohnsonSort(largerElements);

    // Step 3: Initialize main chain with first pair elements
    Container sortedArr;

    // Create a mapping array to track which pair each larger element came from
    std::vector<size_t> pairIndices(pairs.size());
    std::vector<bool> used(pairs.size(), false);

    // Match sorted larger elements back to their original pairs
    for (size_t i = 0; i < largerElements.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (!used[j] && pairs[j].second == largerElements[i]) {
                pairIndices[i] = j;
                used[j] = true;
                break;
            }
        }
    }

    // Initialize with first pair
    sortedArr.push_back(pairs[pairIndices[0]].first);
    sortedArr.push_back(pairs[pairIndices[0]].second);

    // Insert all remaining larger elements in the main chain
    for (size_t i = 1; i < largerElements.size(); ++i) {
        sortedArr.push_back(largerElements[i]);
    }

    // Create pending insertions list
    std::vector<std::pair<int, size_t> > pendingElements;
    for (size_t i = 1; i < pairs.size(); ++i) {
        pendingElements.push_back(std::make_pair(pairs[pairIndices[i]].first, i));
    }

    // Get the Jacobsthal insertion sequence
    std::vector<size_t> insertionSequence = getInsertionSequence(pendingElements.size());

    // Insert remaining elements according to the sequence
    for (size_t i = 0; i < insertionSequence.size(); ++i) {
        size_t idx = insertionSequence[i];
        if (idx < pendingElements.size()) {
            int valueToInsert = pendingElements[idx].first;

            // Find insertion position using binary search
            typename Container::iterator lower = sortedArr.begin();
            typename Container::iterator upper = sortedArr.end();

            while (lower != upper) {
                typename Container::iterator mid = lower;
                std::advance(mid, std::distance(lower, upper) / 2);

                if (*mid < valueToInsert) {
                    lower = mid;
                    ++lower;
                } else {
                    upper = mid;
                }
            }

            sortedArr.insert(lower, valueToInsert);
        }
    }

    // Insert oddNum if exists
    if (isOdd) {
        typename Container::iterator lower = sortedArr.begin();
        typename Container::iterator upper = sortedArr.end();

        while (lower != upper) {
            typename Container::iterator mid = lower;
            std::advance(mid, std::distance(lower, upper) / 2);

            if (*mid < oddNum) {
                lower = mid;
                ++lower;
            } else {
                upper = mid;
            }
        }

        sortedArr.insert(lower, oddNum);
    }

    // Copy sorted array back to original
    arr = sortedArr;
}

#endif // PMERGE_ME_HPP