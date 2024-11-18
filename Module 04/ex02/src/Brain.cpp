#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain: Default Constructor called." << std::endl;
}

Brain::Brain(const Brain& copy) {
    *this = copy;
    std::cout << "Brain: Copy Constructor called." << std::endl;
}

// Deep copy of the ideas array
Brain& Brain::operator=(const Brain& copy) {
    if (this != &copy) {
        for (int i = 0; i < IDEAS_NBR; ++i) {
            ideas[i] = copy.ideas[i];
        }
    }
    std::cout << "Brain: Assignment Operator called." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: Destructor called." << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < IDEAS_NBR) {
        return ideas[index];
    }
    return "";
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < IDEAS_NBR) {
        ideas[index] = idea;
    }
}