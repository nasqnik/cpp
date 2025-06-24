#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _index(0) {}

void PhoneBook::addContact()
{
    int i = _index % 8;

    _contacts[i].promptInput();
    _index++;
}

void PhoneBook::searchContact()
{
    viewContacts();

    int index = -1;
    std::string input;

    do
    {
        std::cout << "Enter an index (1–8) to view details or 0 to cancel: ";
        std::getline(std::cin, input);
        handleEOF();
        index = atoi(input.c_str());  //accepts numbers
        if (index == 0)
            return;
        if (index < 1 || index > 8)
            std::cout << "Invalid index. Try again." << std::endl;
        else if (_contacts[index - 1].getFirstName().empty())
            std::cout << "No such contact. Try again." << std::endl;
    } while (index < 1 || index > 8 || _contacts[index - 1].getFirstName().empty());
    _contacts[index - 1].displayContactLineByLine();
}

void PhoneBook::viewContacts() const
{
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        if (!_contacts[i].getFirstName().empty())
            _contacts[i].displayContact(i);
    }    
}