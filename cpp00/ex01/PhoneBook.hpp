#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        void addContact();
        void searchContact();
        Contact contacts[8];

    private:
        int     _index;
        static bool getIntInput(const std::string &prompt, int &value);


};

#endif