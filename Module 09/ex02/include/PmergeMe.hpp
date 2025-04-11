#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

// utils 
template <typename Iterator> bool _compare(Iterator lv, Iterator rv);
template <typename Iterator> Iterator advance_iterator_by(Iterator it, int steps);
template <typename Iterator> void _swap_with_next_pair(Iterator rightmost_element_it, int pair_group_size);
template <typename Container> void print_container(Container& container);

class PmergeMe
{
private:
    std::vector<int> original_sequence;
    std::vector<int> vector;
    std::deque<int> deque;
    double vector_time;
    double deque_time;

    template <typename Container, typename Chain>
    void fordJohnsonSort(Container &container, int group_size);
    template <typename Container, typename Chain>
    void _merge_phase(Container &container, int group_size);
    template <typename Container, typename Chain>
    void _create_chains(Container &container, int group_size, Chain &main, Chain &pend);
    template <typename Container, typename Chain>
    std::size_t _optimized_insertion(Chain &main, Chain &pend);
    template <typename Container, typename Chain>
    void _insert_remaining(std::size_t container_size, int group_size, Chain &main, Chain &pend, std::size_t processed_pend_elements);
    template <typename Container, typename Chain>
    void _update_container(Container &container, Chain &main, int group_size);

    static std::size_t _jacobsthal_cache[62];
    static std::size_t _calculate_jacobsthal_number(std::size_t n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    static int comparison_counter;

    void parseArguments(int argc, char *argv[]);
    void sort();
    void displayResults() const;
};

template <typename Container, typename Chain>
void PmergeMe::fordJohnsonSort(Container &container, int group_size)
{
    _merge_phase<Container, Chain>(container, group_size);

    Chain main;
    Chain pend;

    _create_chains<Container, Chain>(container, group_size, main, pend);

    std::size_t processed_pend_elements = _optimized_insertion<Container, Chain>(main, pend);

    _insert_remaining<Container, Chain>(container.size(), group_size, main, pend, processed_pend_elements);

    _update_container<Container, Chain>(container, main, group_size);
}

template <typename Container, typename Chain>
void PmergeMe::_merge_phase(Container &container, int group_size)
{
    typedef typename Container::iterator Iterator;

    int group_count = container.size() / group_size;

    if (group_count < 2)
        return;

    int num_group_pairs = group_count / 2;

    Iterator merge_start = container.begin();
    Iterator merge_end = advance_iterator_by(container.begin(), group_size * 2 * num_group_pairs);

    int merge_step = 2 * group_size;
    for (Iterator it = merge_start; it != merge_end; std::advance(it, merge_step)) {
        Iterator current_group_largest_element = advance_iterator_by(it, group_size - 1);
        Iterator next_group_largest_element = advance_iterator_by(it, group_size * 2 - 1);

        if (_compare(next_group_largest_element, current_group_largest_element))
            _swap_with_next_pair(current_group_largest_element, group_size);
    }

    fordJohnsonSort<Container, Chain>(container, group_size * 2);
}

template <typename Container, typename Chain>
void PmergeMe::_create_chains(Container &container, int group_size, Chain &main, Chain &pend)
{
    typedef typename Container::iterator Iterator;

    int group_count = container.size() / group_size;

    for (int i = 0; i < group_count; i++) {
        int largest_element_position = (group_size * i) + group_size - 1;
        Iterator current = advance_iterator_by(container.begin(), largest_element_position);

        if (i == 0 || i % 2 == 1)
            main.push_back(current);
        else
            pend.push_back(current);
    }
}

template <typename Container, typename Chain>
std::size_t PmergeMe::_optimized_insertion(Chain &main, Chain &pend)
{
    typedef typename Container::iterator Iterator;
    typedef typename Chain::iterator ChainIterator;

    std::size_t processed_pend_elements = 0;
    for (std::size_t jacob_index = 2; processed_pend_elements < pend.size(); jacob_index++) {
        std::size_t curr_jacobsthal = _calculate_jacobsthal_number(jacob_index);
        std::size_t group_size = _calculate_jacobsthal_number(jacob_index) - _calculate_jacobsthal_number(jacob_index - 1);
        if (group_size > pend.size() - processed_pend_elements)
            break;

        std::size_t elements_to_insert = group_size;
        int overlap_correction = 0;

        ChainIterator pend_it = advance_iterator_by(pend.begin() + processed_pend_elements, (elements_to_insert - 1));
        while (elements_to_insert--) {
            ChainIterator search_bound = advance_iterator_by(main.begin(), _calculate_jacobsthal_number(jacob_index) + processed_pend_elements - overlap_correction);

            ChainIterator insertion_point = std::upper_bound(main.begin(), search_bound, *pend_it, _compare<Iterator>);
            ChainIterator inserted = main.insert(insertion_point, *pend_it);

            if (std::distance(main.begin(), inserted) == static_cast<std::ptrdiff_t>(curr_jacobsthal + processed_pend_elements))
                overlap_correction++;

            std::advance(pend_it, -1);
        }
        processed_pend_elements += group_size;
    }
    return (processed_pend_elements);
}

template <typename Container, typename Chain>
void PmergeMe::_insert_remaining(std::size_t container_size, int group_size, Chain &main, Chain &pend, std::size_t processed_pend_elements)
{
    typedef typename Container::iterator Iterator;
    typedef typename Chain::iterator ChainIterator;

    int group_count = container_size / group_size;

    bool is_odd = group_count % 2 == 1;
    for (size_t index = processed_pend_elements; index < pend.size(); index++) {
        ChainIterator current = advance_iterator_by(pend.begin(), index);
        ChainIterator bound = advance_iterator_by(main.begin(), main.size() - pend.size() + index + is_odd);

        ChainIterator insertion_point = std::upper_bound(main.begin(), bound, *current, _compare<Iterator>);
        main.insert(insertion_point, *current);
    }
}

template <typename Container, typename Chain>
void PmergeMe::_update_container(Container &container, Chain &main, int group_size)
{
    typedef typename Container::iterator Iterator;
    typedef typename Chain::iterator ChainIterator;

    Container sorted;
    for (ChainIterator it = main.begin(); it != main.end(); it++) {
        for (int group_pos = 0; group_pos < group_size; group_pos++) {
            Iterator group_member_it = *it;
            std::advance(group_member_it, -group_size + group_pos + 1);
            sorted.push_back(*group_member_it);
        }
    }

    std::copy(sorted.begin(), sorted.end(), container.begin());
}

// utils
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

template <typename Container>
void print_container(Container &container)
{
    for (typename Container::const_iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename Iterator>
Iterator advance_iterator_by(Iterator it, int steps)
{
    std::advance(it, steps);
    return it;
}

template <typename Iterator>
bool _compare(Iterator left_value, Iterator right_value)
{
    return *left_value < *right_value;
}

template <typename Iterator>
void _swap_with_next_pair(Iterator last_element_of_first_group, int group_size)
{
    Iterator current_group_start = advance_iterator_by(last_element_of_first_group, -group_size + 1);
    Iterator next_group_start = advance_iterator_by(current_group_start, group_size);

    while (current_group_start != next_group_start) {
        std::iter_swap(current_group_start, advance_iterator_by(current_group_start, group_size));
        current_group_start++;
    }
}


#endif // PMERGE_ME_HPP