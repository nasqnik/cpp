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
        if (command == "ADD")
            phone_book.addContact();
        else if (command == "SEARCH")
            phone_book.search();
        else if (command == "EXIT")
            break;
    }
    return (0);
}