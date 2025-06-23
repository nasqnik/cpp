#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0) {}

void PhoneBook::addContact()
{
    int i = _index % 8;

    contacts[i].inputField("FIRST NAME: ", contacts[i].first_name);
    contacts[i].inputField("LAST NAME: ", contacts[i].last_name);
    contacts[i].inputField("NICKNAME: ", contacts[i].nickname);
    contacts[i].inputField("PHONE NUMBER: ", contacts[i].phone_number);
    contacts[i].inputField("DARKEST SECRET: ", contacts[i].darkest_secret);
    this->_index++;
}
bool PhoneBook::getIntInput(const std::string &prompt, int &value) 
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    if (!(iss >> value) || (value < 0 || value > 7)) 
    {
        std::cout << "Invalid index (from " << 0 << " to " << 7 << ")" << std::endl;
        return false;
    }
    return true;
}

void PhoneBook::searchContact()
{
    std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;

    for (int i = 0; i < 8; i++)
    {
        if (!this->contacts[i].first_name.empty())
            contacts[i].printContact(i, contacts[i]);
    }

    int index;
    while (!PhoneBook::getIntInput("Enter the index of the contact you want to search for: ", index)) 
    {
        if (!this->contacts[index].first_name.empty())
            contacts[index].printContact(index, contacts[index]);
        else
            std::cout << "No contact at this index." << std::endl;
    }
}