#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _index;
        void header() const;
        void searchContact() const;

    public:
        PhoneBook();
        void addContact();
        void search() const;
        void viewContacts() const;
};

#endif