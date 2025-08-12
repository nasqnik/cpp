#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created" << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}
FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap copy assignment operator called for " << 
                _name << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five! ✋" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "FragTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << _name << " doesn't have enough energy or hit points to attack" << std::endl;
    }
}

void FragTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;

    if (_hitPoints <= 0)
        _hitPoints = 0;

    std::cout << "FragTrap " << _name << " takes " << amount << 
                " points of damage. Remaining HP: " << 
                _hitPoints << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;

        std::cout << "FragTrap " << _name << " repairs itself for " << 
                amount << " points! New HP: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "FragTrap " << _name << " can't repair itself!" << std::endl;
    }
}