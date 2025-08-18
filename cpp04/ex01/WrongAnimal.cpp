#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Wrong Animal") {
    std::cout << "Wrong Animal Default constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type) {
    std::cout << "Wrong Animal constructor has been called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type) {
    std::cout << "Wrong Animal Copy constructor has been called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    std::cout << "Wrong Animal Copy Assignment operator has been called" << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Wrong Animal Destructor has been called" << std::endl;
}

const std::string& WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::makeSound() const {
    std::cout << "Random wrong animal sound~" << std::endl;
}