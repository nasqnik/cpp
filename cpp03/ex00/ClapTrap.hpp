#pragma once

#include <string>
#include <iostream>

class ClapTrap
{
    private:
        std::string     _name;
        int    _hitPoints;
        int    _energyPoints;
        int    _attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void setAttackDamage(int amount);
        int getAttackDamage() const;

};