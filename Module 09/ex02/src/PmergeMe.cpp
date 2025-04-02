#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits>

// Constructor
PmergeMe::PmergeMe() : m_vectorTime(0), m_dequeTime(0) {}

// Destructor
PmergeMe::~PmergeMe() {}

// Helper function to check if a string is a positive integer
bool PmergeMe::isPositiveInteger(const std::string& str) const {
    if (str.empty())
        return false;
        
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

// Parse command line arguments into the original sequence
bool PmergeMe::parseArguments(int argc, char* argv[]) {
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

/**
 * @brief Sorts a vector of integers using the Ford-Johnson sorting algorithm (merge-insertion sort).
 * 
 * It works as follows:
 * 
 * 1. **Pairing and Sorting**: Divide the input vector into ⌊n/2⌋ pairs of elements. For each pair, compare 
 *    the two elements and sort them, keeping the smaller element as part of the "main chain" and the larger 
 *    element as part of the "pending chain". If the number of elements is odd, the last element is left unpaired.
 * 
 * 2. **Recursive Sorting**: Recursively sort the "main chain" (smaller elements from each pair) to create a 
 *    sorted sequence `S` of ⌊n/2⌋ elements in ascending order.
 * 
 * 3. **Inserting Pending Elements**: Insert the elements from the "pending chain" (larger elements from each pair) 
 *    into the sorted sequence `S` one at a time. The insertion is performed using binary search to find the 
 *    correct position for each element, ensuring efficient insertion.
 * 
 * 4. **Handling Odd Element**: If there was an unpaired element (in the case of an odd-sized input), it is inserted 
 *    into the sorted sequence `S` using binary search to maintain the sorted order.
 * 
 * 5. **Final Output**: The sorted sequence `S` is copied back to the original vector, completing the sorting process.
 * 
 * @param arr A reference to the vector of integers to be sorted.
 */
void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr, int depth) {
    std::string indent(depth * 2, ' '); // 2 spaces per depth level
    
    #ifdef DEBUG
    std::cout << indent << "🔄 ==== RECURSION LEVEL " << depth << " ==== 🔄" << std::endl;
    std::cout << indent << "Input array: ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "1️⃣ Step 1: Create pairs:" << std::endl;
    #endif

    
    // Step 1: Create pairs
    std::vector<std::pair<int, int> > pairs;
    
    // Check for an odd-sized array
    size_t odd = arr.size() % 2;
    int oddElement = 0;
    if (odd) {
        oddElement = arr[arr.size() - 1];
    }
    
    // Iterate through the array in steps of 2
    for (size_t i = 0; i < arr.size() - odd; i += 2) {
        // Sort each pair
        if (arr[i] > arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        // Store the sorted pairs
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }

    #ifdef DEBUG
    for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
        std::cout << "  (" << it->first << ", " << it->second << ")" << std::endl;
    }
    if (odd) {
        std::cout << indent << "  Odd element: " << oddElement << std::endl;
    }
    #endif

    // Step 2: Sort the pairs based on their larger elements (recursively)
    // Extract larger elements:
    // The pairs vector contains sorted pairs of integers, where the smaller element is stored in pairs[i].first 
    // and the larger element is stored in pairs[i].second. 
    // A new vector, largeElements, is created to store all the larger elements (pairs[i].second) from each pair for further processing.
    std::vector<int> largeElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largeElements.push_back(pairs[i].second);
    }

    #ifdef DEBUG
    std::cout << indent << "2️⃣ Step 2: Recursive sorting of larger elements:" << std::endl;
    std::cout << indent << "  Larger elements: ";
    for (size_t i = 0; i < largeElements.size(); i++) {
        std::cout << largeElements[i] << " ";
    }
    std::cout << std::endl;
    #endif

    // Recursive sorting
    if (largeElements.size() > 1) {

        fordJohnsonSortVector(largeElements, depth + 1);
        
        #ifdef DEBUG
        std::cout << indent << "  Returned from recursive call" << std::endl;
        std::cout << indent << "  Sorted larger elements: ";
        for (size_t i = 0; i < largeElements.size(); i++) {
            std::cout << largeElements[i] << " ";
        }
        std::cout << std::endl;
        #endif
    }
    
    // Step 3: Rebuild the array with the sorted larger elements
    // Initialize the result vector
    std::vector<int> result;    

    #ifdef DEBUG
        std::cout << "3️⃣ Step 3: Rebuilding result array:" << std::endl;
    #endif

    // Iterate through sorted larger elements
    for (size_t i = 0; i < largeElements.size(); i++) {
        // Find the corresponding pair in the pairs vector
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == largeElements[i]) {
                result.push_back(pairs[j].first);
                result.push_back(pairs[j].second);

                #ifdef DEBUG
                std::cout << "  Added pair (" << pairs[j].first << ", " << pairs[j].second << ") to result.\n";
                #endif

                // Remove the processed pair from the pairs vector
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    
    // Step 4: Insert the smaller elements using binary search
    #ifdef DEBUG
    std::cout << "4️⃣ Step 4: Inserting smaller elements into sorted array" << std::endl;
    #endif

    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    
    if (!result.empty()) {
        mainChain.push_back(result[1]);
        pendingChain.push_back(result[0]);
        
        for (size_t i = 2; i < result.size(); i += 2) {
            if (i + 1 < result.size()) {
                mainChain.push_back(result[i + 1]);
                pendingChain.push_back(result[i]);
            }
        }
    }
    
    // Insert pending elements using binary search
    std::vector<int> sortedArray;
    
    if (!mainChain.empty()) {
        sortedArray.push_back(mainChain[0]);
        
        for (size_t i = 0; i < pendingChain.size(); i++) {
            std::vector<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), pendingChain[i]);
            sortedArray.insert(it, pendingChain[i]);
            
            if (i + 1 < mainChain.size()) {
                sortedArray.push_back(mainChain[i + 1]);
            }
        }
    }
    
    // Step 5: Add the odd element (if any) using binary search
    if (odd) {
        std::vector<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), oddElement);
        sortedArray.insert(it, oddElement);

        #ifdef DEBUG
        std::cout << " 5️⃣ Step 5: Inserted odd element " << oddElement << std::endl;
        #endif
    }
    
    // Copy the sorted array back to the original array
    arr = sortedArray;

    // Display final sorted array
    #ifdef DEBUG
    std::cout << indent << " Final sorted array at level " << depth << ":" << std::endl;
    std::cout << indent << "  ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << indent << "🏁 ==== END LEVEL " << depth << " ==== 🏁" << std::endl;
    #endif
}

// void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr, int depth) {
//     std::string indent(depth * 2, ' ');
//     std::string border = indent + std::string(50, '=');
    
//     #ifdef DEBUG
//     std::cout << "\n" << border << std::endl;
//     std::cout << indent << "🔄 STARTING RECURSION LEVEL " << depth << " 🔄" << std::endl;
//     std::cout << border << std::endl;
    
//     std::cout << indent << "📥 Input array [" << arr.size() << " elements]: ";
//     for (size_t i = 0; i < arr.size(); i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl << std::endl;
    
//     std::cout << indent << "1️⃣ STEP 1: CREATING PAIRS" << std::endl;
//     std::cout << indent << "-------------------" << std::endl;
//     #endif
    
//     // Step 1: Create pairs
//     std::vector<std::pair<int, int> > pairs;
    
//     // Check for an odd-sized array
//     size_t odd = arr.size() % 2;
//     int oddElement = 0;
//     if (odd) {
//         oddElement = arr[arr.size() - 1];
//     }
    
//     #ifdef DEBUG
//     std::cout << indent << "  Original array elements: ";
//     for (size_t i = 0; i < arr.size() - odd; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     #endif
    
//     // Iterate through the array in steps of 2
//     for (size_t i = 0; i < arr.size() - odd; i += 2) {
//         #ifdef DEBUG
//         std::cout << indent << "  Pairing: " << arr[i] << " and " << arr[i + 1];
//         #endif
        
//         // Sort each pair
//         if (arr[i] > arr[i + 1]) {
//             std::swap(arr[i], arr[i + 1]);
//             #ifdef DEBUG
//             std::cout << " → swapped to (" << arr[i] << ", " << arr[i + 1] << ")";
//             #endif
//         } else {
//             #ifdef DEBUG
//             std::cout << " → kept as (" << arr[i] << ", " << arr[i + 1] << ")";
//             #endif
//         }
//         #ifdef DEBUG
//         std::cout << std::endl;
//         #endif
        
//         // Store the sorted pairs
//         pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
//     }

//     #ifdef DEBUG
//     std::cout << indent << "  Final pairs [" << pairs.size() << "]: ";
//     for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
//         std::cout << "(" << it->first << "," << it->second << ") ";
//     }
//     std::cout << std::endl;
    
//     if (odd) {
//         std::cout << indent << "  🔍 Odd element: " << oddElement << " (will be inserted later)" << std::endl;
//     }
//     std::cout << std::endl;
//     #endif

//     // Step 2: Sort the pairs based on their larger elements (recursively)
//     // The pairs vector contains sorted pairs of integers, where the smaller element is stored in pairs[i].first 
//     // and the larger element is stored in pairs[i].second. 
//     // A new vector, largeElements, is created to store all the larger elements (pairs[i].second) from each pair for further processing.
//     std::vector<int> largeElements;
//     for (size_t i = 0; i < pairs.size(); i++) {
//         largeElements.push_back(pairs[i].second);
//     }

//     #ifdef DEBUG
//     std::cout << indent << "2️⃣ STEP 2: RECURSIVE SORTING OF LARGER ELEMENTS" << std::endl;
//     std::cout << indent << "-------------------" << std::endl;
//     std::cout << indent << "  Extracting larger elements: ";
//     for (size_t i = 0; i < largeElements.size(); i++) {
//         std::cout << largeElements[i] << " ";
//     }
//     std::cout << std::endl;
//     #endif

//     // Recursive sorting
//     if (largeElements.size() > 1) {
//         #ifdef DEBUG
//         std::cout << indent << "  🔽 Entering recursive call with " << largeElements.size() << " elements..." << std::endl;
//         #endif
        
//         fordJohnsonSortVector(largeElements, depth + 1);
        
//         #ifdef DEBUG
//         std::cout << indent << "  🔼 Returned from recursive call at level " << depth + 1 << std::endl;
//         std::cout << indent << "  Sorted larger elements: ";
//         for (size_t i = 0; i < largeElements.size(); i++) {
//             std::cout << largeElements[i] << " ";
//         }
//         std::cout << std::endl << std::endl;
//         #endif
//     } else {
//         #ifdef DEBUG
//         std::cout << indent << "  ⏹️ Base case reached: only " << largeElements.size() << " element" << std::endl << std::endl;
//         #endif
//     }
    
//     // Step 3: Rebuild the array with the sorted larger elements
//     std::vector<int> result;    

//     #ifdef DEBUG
//     std::cout << indent << "3️⃣ STEP 3: REBUILDING RESULT ARRAY WITH SORTED PAIRS" << std::endl;
//     std::cout << indent << "-------------------" << std::endl;
//     std::cout << indent << "  Pairs before processing: ";
//     for (size_t j = 0; j < pairs.size(); j++) {
//         std::cout << "(" << pairs[j].first << "," << pairs[j].second << ") ";
//     }
//     std::cout << std::endl;
//     #endif

//     // Iterate through sorted larger elements
//     for (size_t i = 0; i < largeElements.size(); i++) {
//         #ifdef DEBUG
//         std::cout << indent << "  Looking for pair with larger element = " << largeElements[i] << std::endl;
//         #endif
        
//         // Find the corresponding pair in the pairs vector
//         for (size_t j = 0; j < pairs.size(); j++) {
//             if (pairs[j].second == largeElements[i]) {
//                 #ifdef DEBUG
//                 std::cout << indent << "    ✅ Found pair (" << pairs[j].first << "," << pairs[j].second << ") at position " << j << std::endl;
//                 #endif
                
//                 result.push_back(pairs[j].first);
//                 result.push_back(pairs[j].second);

//                 #ifdef DEBUG
//                 std::cout << indent << "    Result after adding: ";
//                 for (size_t k = 0; k < result.size(); k++) {
//                     std::cout << result[k] << " ";
//                 }
//                 std::cout << std::endl;
//                 #endif

//                 // Remove the processed pair from the pairs vector
//                 pairs.erase(pairs.begin() + j);
//                 break;
//             }
//         }
//     }
    
//     // Step 4: Insert the smaller elements using binary search
//     #ifdef DEBUG
//     std::cout << std::endl;
//     std::cout << indent << "4️⃣ STEP 4: INSERTING SMALLER ELEMENTS USING BINARY SEARCH" << std::endl;
//     std::cout << indent << "-------------------" << std::endl;
//     std::cout << indent << "  Result vector after rebuild: ";
//     for (size_t i = 0; i < result.size(); i++) {
//         std::cout << result[i] << " ";
//     }
//     std::cout << std::endl;
//     #endif

//     std::vector<int> mainChain;
//     std::vector<int> pendingChain;
    
//     if (!result.empty()) {
//         mainChain.push_back(result[1]);
//         pendingChain.push_back(result[0]);
        
//         for (size_t i = 2; i < result.size(); i += 2) {
//             if (i + 1 < result.size()) {
//                 mainChain.push_back(result[i + 1]);
//                 pendingChain.push_back(result[i]);
//             }
//         }
//     }
    
//     #ifdef DEBUG
//     std::cout << indent << "  Extracting chains:" << std::endl;
//     std::cout << indent << "    MainChain (sorted larger elements): ";
//     for (size_t i = 0; i < mainChain.size(); i++) {
//         std::cout << mainChain[i] << " ";
//     }
//     std::cout << std::endl;
    
//     std::cout << indent << "    PendingChain (smaller elements to insert): ";
//     for (size_t i = 0; i < pendingChain.size(); i++) {
//         std::cout << pendingChain[i] << " ";
//     }
//     std::cout << std::endl << std::endl;
//     #endif
    
//     // Insert pending elements using binary search
//     std::vector<int> sortedArray;
    
//     if (!mainChain.empty()) {
//         sortedArray.push_back(mainChain[0]);
        
//         #ifdef DEBUG
//         std::cout << indent << "  Starting sortedArray with first main element: " << mainChain[0] << std::endl;
//         #endif
        
//         for (size_t i = 0; i < pendingChain.size(); i++) {
//             #ifdef DEBUG
//             std::cout << indent << "  Inserting pending element " << pendingChain[i] << std::endl;
//             std::cout << indent << "    Before insertion: ";
//             for (size_t k = 0; k < sortedArray.size(); k++) {
//                 std::cout << sortedArray[k] << " ";
//             }
//             std::cout << std::endl;
//             #endif
            
//             std::vector<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), pendingChain[i]);
//             size_t pos = it - sortedArray.begin();
//             sortedArray.insert(it, pendingChain[i]);
            
//             #ifdef DEBUG
//             std::cout << indent << "    After insertion at position " << pos << ": ";
//             for (size_t k = 0; k < sortedArray.size(); k++) {
//                 std::cout << sortedArray[k] << " ";
//             }
//             std::cout << std::endl;
//             #endif
            
//             if (i + 1 < mainChain.size()) {
//                 #ifdef DEBUG
//                 std::cout << indent << "    Adding next main element: " << mainChain[i + 1] << std::endl;
//                 #endif
                
//                 sortedArray.push_back(mainChain[i + 1]);
                
//                 #ifdef DEBUG
//                 std::cout << indent << "    Updated array: ";
//                 for (size_t k = 0; k < sortedArray.size(); k++) {
//                     std::cout << sortedArray[k] << " ";
//                 }
//                 std::cout << std::endl;
//                 #endif
//             }
//         }
//     }
    
//     // Step 5: Add the odd element (if any) using binary search
//     if (odd) {
//         #ifdef DEBUG
//         std::cout << std::endl;
//         std::cout << indent << "5️⃣ STEP 5: INSERTING ODD ELEMENT" << std::endl;
//         std::cout << indent << "-------------------" << std::endl;
//         std::cout << indent << "  Before insertion: ";
//         for (size_t i = 0; i < sortedArray.size(); i++) {
//             std::cout << sortedArray[i] << " ";
//         }
//         std::cout << std::endl;
//         std::cout << indent << "  Inserting odd element: " << oddElement << std::endl;
//         #endif
        
//         std::vector<int>::iterator it = std::lower_bound(sortedArray.begin(), sortedArray.end(), oddElement);
//         size_t pos = it - sortedArray.begin();
//         sortedArray.insert(it, oddElement);
        
//         #ifdef DEBUG
//         std::cout << indent << "  After insertion at position " << pos << ": ";
//         for (size_t i = 0; i < sortedArray.size(); i++) {
//             std::cout << sortedArray[i] << " ";
//         }
//         std::cout << std::endl;
//         #endif
//     }
    
//     // Copy the sorted array back to the original array
//     arr = sortedArray;

//     // Display final sorted array
//     #ifdef DEBUG
//     std::cout << std::endl;
//     std::cout << indent << "🏁 FINAL SORTED ARRAY AT LEVEL " << depth << ":" << std::endl;
//     std::cout << indent << "  ";
//     for (size_t i = 0; i < arr.size(); i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
//     std::cout << border << std::endl;
//     #endif
// }

// Ford-Johnson sort implementation for std::deque
void PmergeMe::fordJohnsonSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;
    
    // Step 1: Create pairs and sort them
    std::deque<std::pair<int, int> > pairs;
    size_t odd = deq.size() % 2;
    int oddElement = 0;
    
    if (odd) {
        oddElement = deq.back();
    }
    
    // Process pairs
    for (size_t i = 0; i < deq.size() - odd; i += 2) {
        if (deq[i] > deq[i + 1])
            std::swap(deq[i], deq[i + 1]);
        pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
    }
    
    // Step 2: Sort the pairs based on their larger elements (recursively)
    std::deque<int> largeElements;
    for (size_t i = 0; i < pairs.size(); i++) {
        largeElements.push_back(pairs[i].second);
    }
    
    if (largeElements.size() > 1) {
        fordJohnsonSortDeque(largeElements);
    }
    
    // Step 3: Rebuild using the sorted larger elements
    std::deque<int> result;
    for (size_t i = 0; i < largeElements.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == largeElements[i]) {
                result.push_back(pairs[j].first);
                result.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    
    // Step 4: Insert the smaller elements using binary search
    std::deque<int> mainChain;
    std::deque<int> pendingChain;
    
    if (!result.empty()) {
        mainChain.push_back(result[1]);
        pendingChain.push_back(result[0]);
        
        for (size_t i = 2; i < result.size(); i += 2) {
            if (i + 1 < result.size()) {
                mainChain.push_back(result[i + 1]);
                pendingChain.push_back(result[i]);
            }
        }
    }
    
    // Insert pending elements using binary search
    std::deque<int> sortedDeque;
    
    if (!mainChain.empty()) {
        sortedDeque.push_back(mainChain[0]);
        
        for (size_t i = 0; i < pendingChain.size(); i++) {
            std::deque<int>::iterator it = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), pendingChain[i]);
            sortedDeque.insert(it, pendingChain[i]);
            
            if (i + 1 < mainChain.size()) {
                sortedDeque.push_back(mainChain[i + 1]);
            }
        }
    }
    
    // Step 5: Add the odd element (if any) using binary search
    if (odd) {
        std::deque<int>::iterator it = std::lower_bound(sortedDeque.begin(), sortedDeque.end(), oddElement);
        sortedDeque.insert(it, oddElement);
    }
    
    // Copy the sorted deque back to the original deque
    deq = sortedDeque;
}

// Sort the sequence using both container types
void PmergeMe::sort() {
    // Initialize containers
    m_vectorSorted = m_originalSequence;
    m_dequeSorted.assign(m_originalSequence.begin(), m_originalSequence.end());
    
    // Sort with vector and measure time
    clock_t startVector = clock();
    fordJohnsonSortVector(m_vectorSorted);
    clock_t endVector = clock();
    m_vectorTime = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000; // µs
    
    // Sort with deque and measure time
    clock_t startDeque = clock();
    fordJohnsonSortDeque(m_dequeSorted);
    clock_t endDeque = clock();
    m_dequeTime = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; // µs
}

// Display the results as required
void PmergeMe::displayResults() const {
    // Display unsorted sequence
    std::cout << "Before: ";
    for (size_t i = 0; i < m_originalSequence.size(); i++) {
        std::cout << m_originalSequence[i] << " ";
    }
    std::cout << std::endl;
    
    // Display sorted sequence
    std::cout << "After: ";
    for (size_t i = 0; i < m_vectorSorted.size(); i++) {
        std::cout << m_vectorSorted[i] << " ";
    }
    std::cout << std::endl;
    
    // Display execution times
    std::cout << "Time to process a range of " << m_originalSequence.size() 
              << " elements with std::vector : " << m_vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << m_originalSequence.size() 
              << " elements with std::deque : " << m_dequeTime << " us" << std::endl;
}

// Getters
const std::vector<int>& PmergeMe::getOriginalSequence() const {
    return m_originalSequence;
}

const std::vector<int>& PmergeMe::getVectorSorted() const {
    return m_vectorSorted;
}

const std::deque<int>& PmergeMe::getDequeSorted() const {
    return m_dequeSorted;
}

double PmergeMe::getVectorTime() const {
    return m_vectorTime;
}

double PmergeMe::getDequeTime() const {
    return m_dequeTime;
}