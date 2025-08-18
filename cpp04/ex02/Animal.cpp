#include "Animal.hpp"

// Orthodox Canonical Form Class
AAnimal::AAnimal(): _type("Animal") {
    std::cout << "Animal Default constructor has been called" << std::endl;
}

AAnimal::AAnimal(const std::string& type): _type(type) {
    std::cout << "Animal constructor has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
    std::cout << "Animal Copy constructor has been called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
    std::cout << "Animal Copy assignment operator has been called" << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Animal Destructor has been called" << std::endl;
}

const std::string& AAnimal::getType() const {
    return _type;
}
