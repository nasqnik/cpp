#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat") {
    std::cout << "Cat Constructor has been called" << std::endl;
    _brain = new Brain("Cat");
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
    std::cout << "Cat Copy constructor has been called" << std::endl;
    _brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy Assignment operator has been called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat Destructor has been called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Meow meow meow 🐱" << std::endl;
}

Brain* Cat::getBrain() const {
    return _brain;
}