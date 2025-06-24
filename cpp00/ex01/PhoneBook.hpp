#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

void handleEOF();

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _index;

    public:
        PhoneBook();
        void addContact();
        void searchContact();
        void viewContacts() const;
};

#endif