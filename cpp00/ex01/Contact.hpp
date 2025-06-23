#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Contact
{
    public:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;

        void printContact(int index, const Contact &c);
        void inputField(const std::string &prompt, std::string &field);
};

#endif