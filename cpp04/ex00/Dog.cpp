#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor has been called" << std::endl;
}

Dog::Dog(const Dog &other)
    : Animal(other)
{
    std::cout << "Dog copy constructor has been called" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator has been called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor has been called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof woof woof 🐶" << std::endl;
}