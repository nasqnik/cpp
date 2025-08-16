#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat Constructor has been called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor has been called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy Assignment operator has been called" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor has been called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow meow meow 🐱" << std::endl;
}