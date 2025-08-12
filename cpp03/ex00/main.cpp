#include "ClapTrap.hpp"

int main()
{

    ClapTrap a("A");
    ClapTrap b("B");
    std::cout << std::endl;

    a.setAttackDamage(3);
    b.setAttackDamage(4);
    std::cout << std::endl;

    a.attack("B");
    b.takeDamage(a.getAttackDamage());
    std::cout << std::endl;

    b.beRepaired(5);
    std::cout << std::endl;

    b.attack("A");
    a.takeDamage(b.getAttackDamage());
    std::cout << std::endl;

    a.beRepaired(2);
    std::cout << std::endl;

    a.setAttackDamage(1);
    for (int i = 0; i < 9; i++)
        a.attack("Dummy");
    std::cout << std::endl;

    a.beRepaired(3);
    std::cout << std::endl;

    // Test copy constructor
    std::cout << "=== Testing Copy Constructor ===" << std::endl;
    ClapTrap copyA(a);
    std::cout << std::endl;

    // Test assignment operator
    std::cout << "=== Testing Assignment Operator ===" << std::endl;
    ClapTrap assignedB("Temp");
    assignedB = b;
    std::cout << std::endl;

    return 0;

    //he has to die :)
}