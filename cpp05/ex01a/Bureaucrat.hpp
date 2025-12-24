#pragma once

#include "Form.hpp"

#include <string>
#include <iostream>
#include <exception>


class Form;

class Bureaucrat 
{
    private:
        int _grade;
        const std::string _name;

    public:
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        // Constructor
        Bureaucrat(const std::string& name, int grade);

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Actions
        void incrementGrade();
        void decrementGrade();
        void signForm(Form &f);

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

    };

    std::ostream& operator<<(std::ostream& os, const Bureaucrat &b); 