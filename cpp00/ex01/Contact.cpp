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

std::string Contact::trim(const std::string& str)
{
    size_t first = 0;
    while (first < str.length() && std::isspace(str[first]))
        ++first;

    size_t last = str.length();
    while (last > first && std::isspace(str[last - 1]))
        --last;

    return str.substr(first, last - first);
}

void Contact::addInput(const std::string &prompt, std::string &field)
{
    std::string temp;

    do
    {
        std::cout << prompt;
        std::getline(std::cin, temp);
        field = trim(temp);
        handleEOF();
    } while (field.empty() || isOnlySpaces(field));
}


bool Contact::isOnlySpaces(const std::string &input) const
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isspace(input[i]))
            return false;
    }
    return true;
}

std::string Contact::formatField(const std::string &str) const
{
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

void Contact::displayContactLineByLine() const
{
    displayLine("FIRST NAME: ", _firstName);
    displayLine("LAST NAME: ", _lastName);
    displayLine("NICKNAME: ", _nickname);
    displayLine("PHONE NUMBER: ", _phoneNumber);
    displayLine("DARKEST SECRET: ", _darkestSecret);
}

void Contact::displayLine(const std::string &field_name, const std::string &value) const
{
    std::cout << field_name << value << std::endl;
}
