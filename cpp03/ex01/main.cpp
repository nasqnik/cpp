#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav("Guardian");
    std::cout << std::endl;

    scav.attack("intruder");
    std::cout << std::endl;

    scav.takeDamage(20);
    std::cout << std::endl;

    scav.beRepaired(10);
    std::cout << std::endl;

    scav.guardGate();
    std::cout << std::endl;

    ScavTrap scavCopy(scav);
    std::cout << std::endl;

    ScavTrap scavAssigned("Temp");
    std::cout << std::endl;
    scavAssigned = scav;

    return 0;
}