#include "PhoneBook.hpp"
#include <sstream>

PhoneBook::PhoneBook(): _index(0) {}

void PhoneBook::addContact()
{
    int i = _index % 8;

    _contacts[i].promptInput();
    _index++;
}

void PhoneBook::search() const
{
    if (_contacts[0].getFirstName().empty())
    {
        std::cout << "Please add a contact first" << std::endl;
        return;
    }
    else
        searchContact();
}

void PhoneBook::searchContact() const
{
    viewContacts();

    int index = -1;
    std::string input;

    while (true)
    {
        std::cout << "Enter an index (1–8) to view details or 0 to cancel: ";
        std::getline(std::cin, input);
        handleEOF();

        std::stringstream ss(input);
        if (!(ss >> index) || !ss.eof()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        if (index == 0)
            return;
        if (index < 1 || index > 8)
            std::cout << "Invalid index. Try again." << std::endl;
        else if (_contacts[index - 1].getFirstName().empty())
            std::cout << "No such contact. Try again." << std::endl;
        else
            break;
    }
    _contacts[index - 1].displayContactLineByLine();
}

void PhoneBook::header() const
{
    std::cout << "|" 
              << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME" << "|" 
              << std::endl;
}

void PhoneBook::viewContacts() const
{
    header();
    for (int i = 0; i < 8; i++)
    {
        if (!_contacts[i].getFirstName().empty())
            _contacts[i].displayContact(i);
    }    
}