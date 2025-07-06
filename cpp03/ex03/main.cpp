#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("Shiny");

    dt.attack("Target Dummy");
    dt.takeDamage(30);
    dt.beRepaired(20);

    dt.whoAmI();

    DiamondTrap copyDt(dt);
    copyDt.whoAmI();

    DiamondTrap anotherDt("Another");
    anotherDt = dt;
    anotherDt.whoAmI();

    return 0;
}