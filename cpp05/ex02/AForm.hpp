#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {

    private:
        const std::string _name;
        bool _signed;
        const int _gradeSign;
        const int _gradeExec;

    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

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

    class FormNotSignedException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const &executor) const;

    protected:
        virtual void executeForm(Bureaucrat const &executor) const = 0;

};

// Operator overload
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif