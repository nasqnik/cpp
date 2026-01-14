#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {

     private:
        const std::string _name;
        int               _grade;
        
        void setGrade(int grade);

    public:
        // Orthodox Canonical Form
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Getters
        const std::string& getName() const;
        int getGrade() const;

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

        // Actions
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &f);
        void executeForm(AForm const & form) const;
};
    
// Operator overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif