#include "ScavTrap.hpp"

ScavTrap::ScavTrap()  
    : ClapTrap("Default")
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)  
    : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other) 
{
    std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap copy assignment operator called for " << 
                _name << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << _name << " is destroyed" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << 
                " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " doesn't have enough energy or hit points to attack" << std::endl;
    }
}

void ScavTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;

    if (_hitPoints <= 0)
        _hitPoints = 0;

    std::cout << "ScavTrap " << _name << " takes " << amount << 
                " points of damage. Remaining HP: " << 
                _hitPoints << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;

        std::cout << "ScavTrap " << _name << " repairs itself for " << 
                amount << " points! New HP: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " can't repair itself!" << std::endl;
    }
}