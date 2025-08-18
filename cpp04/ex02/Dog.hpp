#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &other);
        Dog& operator=(const Dog &other);
        ~Dog();

        void makeSound() const;
        Brain* getBrain() const;
};