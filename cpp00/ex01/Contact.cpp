#include "Contact.hpp"

std::string formatField(const std::string &str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return std::string(10 - str.length(), ' ') + str;
}

void Contact::printContact(int index, const Contact &c)
{
    std::ostringstream num;
    num << index;
    std::string i = num.str();

    std::cout << "|" 
              << formatField(i) << "|"
              << formatField(c.first_name) << "|"
              << formatField(c.last_name) << "|"
              << formatField(c.nickname) << "|" << std::endl;
}

void Contact::inputField(const std::string &prompt, std::string &field) {
    std::cout << prompt;
    std::getline(std::cin, field);
    while (field.empty()) {
        std::cout << prompt << " cannot be empty. Please enter again: ";
        std::getline(std::cin, field);
    }
}