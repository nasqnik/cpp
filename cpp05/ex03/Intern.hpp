#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern {

    private:
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPardon(const std::string& target);

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
        
        class UnknownFormException : public std::exception {
            public:
            const char *what() const throw();
        };
        
        AForm* makeForm(const std::string& formName, const std::string& target);
    };

#endif