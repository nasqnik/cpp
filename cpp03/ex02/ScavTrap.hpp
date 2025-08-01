#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

    public:
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ScavTrap &operator=(const ScavTrap &other);
        ~ScavTrap();

        void guardGate();
};