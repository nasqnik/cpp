#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : type(weapon) {};

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}