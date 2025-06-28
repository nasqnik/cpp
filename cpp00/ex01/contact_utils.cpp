#include "Contact.hpp"

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

bool Contact::isOnlySpaces(const std::string &input) const
{
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isspace(input[i]))
            return false;
    }
    return true;
}

bool Contact::isValidPhoneNumber(const std::string &phone) const
{
    for (size_t i = 0; i < phone.length(); i++)
    {
        if (!std::isdigit(phone[i]))
        {
            std::cout << "Error: phone number can contain only digits" << std::endl;
            return false;
        }
    }
    return true;
}
std::string Contact::truncateField(const std::string &str) const
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayLine(const std::string &field_name, const std::string &value) const
{
    std::cout << field_name << value << std::endl;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}