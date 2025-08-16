#include "Animal.hpp"

// Orthodox Canonical Form Class
Animal::Animal(): _type("Animal") {
    std::cout << "Animal Default constructor has been called" << std::endl;
}

Animal::Animal(const std::string& type): _type(type) {
    std::cout << "Animal constructor has been called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << "Animal Copy constructor has been called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal Destructor has been called" << std::endl;
}

const std::string& Animal::getType() const {
    return _type;
}

void Animal::makeSound() const {
    std::cout << "Random animal sound~" << std::endl;
}