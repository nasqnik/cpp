#include "Brain.hpp"
#include <sstream>

// Orthodox Canonical Form Class
Brain::Brain() {
    std::cout << "Brain Default constructor has been called" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        std::ostringstream oss;
        oss << "Default idea " << i;
        ideas[i] = oss.str();
    }
}

Brain::Brain(const std::string& type) {
    std::cout << "Brain constructor has been called" << std::endl;
    for (int i = 0; i < 100; ++i)
    {
        std::ostringstream oss;
        oss << type << "'s idea " << i;
        ideas[i] = oss.str();
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain Copy constructor has been called" << std::endl;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain &other)
{
    std::cout << "Brain Copy assignment operator has been called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain Destructor has been called" << std::endl;
}

std::string Brain::getIdea(int i) const {
    if (i >= 0 && i < 100)
        return ideas[i];
    return "";
}

void Brain::setIdea(int i, const std::string& idea) {
    if (i >= 0 && i < 100)
        ideas[i] = idea;
}