#include "Contact.hpp"

void handleEOF() 
{
    if (std::cin.eof()) 
    {
        std::cout << "\nEOF detected. Exiting program." << std::endl;
        exit(0);
    }
}

void Contact::setFirstName(const std::string &value)
{
    _firstName = value;
}

void Contact::setLastName(const std::string &value)
{
    _lastName = value;
}

void Contact::setNickname(const std::string &value)
{
    _nickname = value;
}

void Contact::setPhoneNumber(const std::string &value)
{
    _phoneNumber = value;
}

void Contact::setDarkestSecret(const std::string &value)
{
    _darkestSecret = value;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

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
    do
    {
        std::cout << prompt;
        std::getline(std::cin, field);
        handleEOF();
    } while (field.empty());
}

std::string formatField(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void Contact::displayContact(int i) const
{
    std::ostringstream num;
    num << i + 1;
    std::string index = num.str();

    std::cout << "|" 
              << formatField(index) << "|"
              << formatField(_firstName) << "|"
              << formatField(_lastName) << "|"
              << formatField(_nickname) << "|" << std::endl;
}

void displayLine(const std::string &field_name, const std::string &value)
{
    std::cout << field_name << value << std::endl;
}
void Contact::displayContactLineByLine() const
{
    displayLine("FIRST NAME: ", _firstName);
    displayLine("LAST NAME: ", _lastName);
    displayLine("NICKNAME: ", _nickname);
    displayLine("PHONE NUMBER: ", _phoneNumber);
    displayLine("DARKEST SECRET: ", _darkestSecret);
}