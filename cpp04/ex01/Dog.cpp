#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog Constructor has been called" << std::endl;
    _brain = new Brain("Dog");
}

Dog::Dog(const Dog &other)
    : Animal(other)
{
    std::cout << "Dog Copy constructor has been called" << std::endl;
    _brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog &other)
{
    std::cout << "Dog Copy assignment operator has been called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        if (_brain)
            delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog Destructor has been called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "Woof woof woof 🐶" << std::endl;
}

Brain* Dog::getBrain() const {
    return _brain;
}