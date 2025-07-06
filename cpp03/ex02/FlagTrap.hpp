#pragma once
#include "ClapTrap.hpp"

#include <string>

class FlagTrap : public ClapTrap
{
    public:
        FlagTrap(const std::string &name);
        FlagTrap(const FlagTrap& other);
        FlagTrap &operator=(const FlagTrap &other);
        ~FlagTrap();
        void highFivesGuys(void);
};