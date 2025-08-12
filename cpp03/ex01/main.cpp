#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Guardian");
    std::cout << std::endl;

    for (int i = 0; i < 5; i++) {
        scav.attack("Dummy");
    }
    std::cout << std::endl;

    scav.takeDamage(100);
    scav.attack("Target");
    scav.beRepaired(50);
    std::cout << std::endl;

    scav.guardGate();
    std::cout << std::endl;

    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    ScavTrap scavCopy(scav);
    std::cout << std::endl;

    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    ScavTrap scavAssigned("Temp");
    scavAssigned = scav;

    std::cout << std::endl;

    return 0;
}