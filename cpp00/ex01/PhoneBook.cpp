#include <iostream>
#include <string>

int main()
{
    std::string command;

    while (true)
    {
        std::cout << "Pick the command ADD, SEARCH or EXIT, and enter it" << std::endl;
        std::cin >> command;
        if (std::strcmp(command.c_str(), "ADD") == 0)
            std::cout << "Added" << std::endl;
        else if (std::strcmp(command.c_str(), "SEARCH") == 0)
            std::cout << "Searched" << std::endl;
        else if (std::strcmp(command.c_str(), "EXIT") == 0)
            std::cout << "Exited" << std::endl;
        
    }
    return (0);
}