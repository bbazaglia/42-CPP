#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define IDEAS_NBR 100

class Brain {
public:
    Brain();
    Brain(const Brain& copy);
    Brain& operator=(const Brain& copy);
    ~Brain();

    std::string getIdea(int index) const;
    void setIdea(int index, const std::string& idea);

private:
    std::string ideas[IDEAS_NBR];
};

#endif