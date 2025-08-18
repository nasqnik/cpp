#pragma once

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string _type;
    
    public:
        AAnimal();
        AAnimal(const std::string& type);
        AAnimal(const AAnimal &other);
        AAnimal& operator=(const AAnimal &other);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;
        const std::string& getType() const;
};