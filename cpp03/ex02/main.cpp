#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FlagTrap.hpp"

int main()
{
    ClapTrap basic("BasicBot");
    ScavTrap guard("GuardBot");
    FlagTrap highfiver("HighFiveBot");

    std::cout << std::endl;

    basic.attack("Target1");
    basic.takeDamage(5);
    basic.beRepaired(3);

    std::cout << std::endl;

    guard.attack("Target2");
    guard.takeDamage(20);
    guard.beRepaired(10);
    guard.guardGate();

    std::cout << std::endl;

    highfiver.attack("Target3");
    highfiver.takeDamage(30);
    highfiver.beRepaired(20);
    highfiver.highFivesGuys();

    std::cout << std::endl;

    return 0;
}