#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // ClapTrap basics
    ClapTrap ct("CT");
    ct.setAttackDamage(2);
    ct.attack("Dummy");
    ct.takeDamage(1);
    ct.beRepaired(1);
    std::cout << std::endl;

    // Energy depletion (ClapTrap has 10 energy)
    for (int i = 0; i < 10; ++i)
        ct.attack("EnergySink");
    ct.attack("ShouldFailNoEnergy");
    std::cout << std::endl;

    // HP boundary
    ct.takeDamage(1000);     // drop to 0 HP
    ct.attack("ShouldFailNoHP");
    ct.beRepaired(5);        // should fail due to 0 HP or 0 energy
    std::cout << std::endl;

    // OCF: copy constructor + assignment + self-assignment
    std::cout << "=== ClapTrap OCF ===" << std::endl;
    ClapTrap ctCopy(ct);
    ClapTrap ctAssigned("TempCT");
    ctAssigned = ct;
    ctAssigned = ctAssigned; // self-assignment
    std::cout << std::endl;

    // ScavTrap basics + special ability
    ScavTrap st("ST");
    st.setAttackDamage(5);
    st.attack("Target");
    st.takeDamage(20);
    st.beRepaired(10);
    st.guardGate();
    std::cout << std::endl;

    // ScavTrap OCF
    std::cout << "=== ScavTrap OCF ===" << std::endl;
    ScavTrap stCopy(st);
    ScavTrap stAssigned("TempST");
    stAssigned = st;
    stAssigned = stAssigned;
    std::cout << std::endl;

    // FragTrap basics + special ability
    FragTrap ft("FT");
    ft.setAttackDamage(7);
    ft.attack("Target");
    ft.takeDamage(30);
    ft.beRepaired(20);
    ft.highFivesGuys();
    std::cout << std::endl;

    // FragTrap OCF
    std::cout << "=== FragTrap OCF ===" << std::endl;
    FragTrap ftCopy(ft);
    FragTrap ftAssigned("TempFT");
    ftAssigned = ft;
    ftAssigned = ftAssigned;
    std::cout << std::endl;

    // Energy boundary examples for derived classes (short)
    for (int i = 0; i < 5; ++i) st.attack("Dummy");
    for (int i = 0; i < 5; ++i) ft.attack("Dummy");
    std::cout << std::endl;

    return 0;
}