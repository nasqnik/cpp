#include "FlagTrap.hpp"

FlagTrap::FlagTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FlagTrap " << _name << " is created" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& other)
    : ClapTrap(other)
{
    std::cout << "FlagTrap copy constructor called for " << _name << std::endl;
}
FlagTrap& FlagTrap::operator=(const FlagTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FlagTrap copy assignment operator called for " << 
                _name << std::endl;
    return *this;
}

FlagTrap::~FlagTrap()
{
    std::cout << "FlagTrap " << _name << " is destroyed" << std::endl;
}

void FlagTrap::highFivesGuys()
{
    std::cout << "FlagTrap " << _name << " requests a high five! ✋" << std::endl;
}