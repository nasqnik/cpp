#include "Contact.hpp"

void Contact::promptInput()
{
    addInput("FIRST NAME: ", _firstName);
    addInput("LAST NAME: ", _lastName);
    addInput("NICKNAME: ", _nickname);
    addInput("PHONE NUMBER: ", _phoneNumber);
    addInput("DARKEST SECRET: ", _darkestSecret);
}

void Contact::addInput(const std::string &prompt, std::string &field)
{
    std::string temp;

    do
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        handleEOF();
        field = trim(temp);
    } while (field.empty() || isOnlySpaces(field) 
        || (&field == &_phoneNumber && !isValidPhoneNumber(field)));
}

void Contact::displayContact(int i) const
{
    std::cout << "|" 
              << std::setw(10) << (i + 1) << "|"
              << std::setw(10) << truncateField(_firstName) << "|"
              << std::setw(10) << truncateField(_lastName) << "|"
              << std::setw(10) << truncateField(_nickname) << "|" 
              << std::endl;
}

void Contact::displayContactLineByLine() const
{
    displayLine("FIRST NAME: ", _firstName);
    displayLine("LAST NAME: ", _lastName);
    displayLine("NICKNAME: ", _nickname);
    displayLine("PHONE NUMBER: ", _phoneNumber);
    displayLine("DARKEST SECRET: ", _darkestSecret);
}
