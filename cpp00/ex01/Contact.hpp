#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

void handleEOF();

class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    
        void addInput(const std::string &prompt, std::string &field);
        void displayLine(const std::string &field_name, const std::string &value) const;
        bool isOnlySpaces(const std::string &input) const;
        bool isValidPhoneNumber(const std::string &phone) const;
        std::string truncateField(const std::string &str) const;
        std::string trim(const std::string& str);
        
    public:
        std::string getFirstName() const;

        void promptInput();
        void displayContact(int i) const;
        void displayContactLineByLine() const;
};

#endif