#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

    private:
        const std::string _name;
        int               _grade;

    public:
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat(const std::string& name, int grade);

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Setter
        void setGrade(int grade);

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // Grade Increment / Decrement
        void incrementGrade();
        void decrementGrade();
};
    
// Operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif