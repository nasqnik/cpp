#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat") {
    std::cout << "WrongCat constructor has been called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "WrongCat Copy Constructor has been called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat Copy Assignment operator has been called" << std::endl;
    
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor has been called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow meow meow" << std::endl;
}