#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : 
    _name(name),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " is created" << std::endl;
};

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " is destroyed" << std::endl;
};

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
}

ClapTrap&   ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::setAttackDamage(int amount)
{
    std::cout << "ClapTrap " << _name << " sets the attack damage to " <<
                amount << std::endl;
    _attackDamage = amount;
}

int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << 
                    target << " causing " << _attackDamage << 
                    " points of damage!" << std::endl;
        _energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " doesn't have enough" << 
                    " energy or hit points to attack" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;

    if (_hitPoints <= 0)
        _hitPoints = 0;

    std::cout << "ClapTrap " << _name << " takes " << amount << 
                " points of damage. Remaining HP: " << 
                _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _hitPoints += amount;
        _energyPoints--;

        std::cout << "ClapTrap " << _name << " repairs itself for " << 
                amount << " points! New HP: " << _hitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " can't repair itself!" << std::endl;
    }
}