#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\nIf you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int choice = -1;

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            choice = i;
            break;
        }
    }

    switch (choice)
    {
        case 0:
            std::cout << "[ DEBUG ]"<< std::endl;
            (this->*functions[choice++])();
            std::cout << std::endl;
        case 1:
            std::cout << "[ INFO ]"<< std::endl;
            (this->*functions[choice++])();
            std::cout << std::endl;
        case 2:
            std::cout << "[ WARNING ]"<< std::endl;
            (this->*functions[choice++])();
            std::cout << std::endl;
        case 3:
            std::cout << "[ ERROR ]"<< std::endl;
            (this->*functions[choice])();
            std::cout << std::endl;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]"<< std::endl;

    }
}