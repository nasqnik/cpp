#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form {

    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        Form();
        Form(const std::string& name, int gradeSign, int gradeExec);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

    // Getters / Setters
        const std::string& getName() const;
        bool getSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;

        void setSigned(bool sign);

    // Exception classes

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class FormAlreadySignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    void beSigned(const Bureaucrat& b);
};

// Operator overload
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif