#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form 
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        // Orthodox Canonical Form
        Form();
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();
        
        // Constructor
        Form(const std::string& name, int gradeSign, int gradeExec);

        // Getters
        const std::string& getName() const;
        bool isSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        // Actions
        void beSigned(const Bureaucrat& b);

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

std::ostream& operator<<(std::ostream& os, const Form& f); 
