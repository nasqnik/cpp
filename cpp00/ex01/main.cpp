#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    std::string command;
    PhoneBook   phone_book;

    while (true)
    {
        std::cout << "Pick the command ADD, SEARCH or EXIT, and enter it" << std::endl;
        std::getline(std::cin, command);
        handleEOF();
        if (std::strcmp(command.c_str(), "ADD") == 0)
            phone_book.addContact();
        else if (std::strcmp(command.c_str(), "SEARCH") == 0)
            phone_book.searchContact();
        else if (std::strcmp(command.c_str(), "EXIT") == 0)
            break;
    }
    return (0);
}