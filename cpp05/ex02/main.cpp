#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << std::endl;
    std::cout << "-----SHRUBBERY CREATION FORM-----" << std::endl;
    std::cout << std::endl;
    {
        std::cout << "-----Orthodox Canonical Form Check-----" << std::endl;
        
        ShrubberyCreationForm a;

        std::cout << a << std::endl;
        std::cout << std::endl;

        ShrubberyCreationForm b("file1");
        std::cout << b << std::endl;
        std::cout << std::endl;

        ShrubberyCreationForm c(b);
        std::cout << c << std::endl;
        std::cout << std::endl;

        a.setTarget("file2");
        b = a;
        std::cout << b << std::endl;
        std::cout << std::endl;

    }
    std::cout << std::endl;
    {
        std::cout << "-----Form Execution Check-----" << std::endl;

        ShrubberyCreationForm file1("file_1");
        std::cout << file1 << std::endl;
        std::cout << std::endl;

        Bureaucrat a("A", 150);
        std::cout << a << std::endl;
        a.signForm(file1); // won't be able to sign
        a.executeForm(file1); // shouldn't execute
        std::cout << std::endl;

        Bureaucrat b("B", 140);
        std::cout << b << std::endl;
        b.signForm(file1); // will sign
        b.executeForm(file1); // won't be able to execute
        std::cout << std::endl;
        
        Bureaucrat c("C", 130);
        std::cout << c << std::endl;
        c.signForm(file1); // form is already signed
        c.executeForm(file1); // will execute
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-----ROBOTOMY REQUEST FORM-----" << std::endl;
    std::cout << std::endl;
    {
        std::cout << "-----Orthodox Canonical Form Check-----" << std::endl;
        
        RobotomyRequestForm a;

        std::cout << a << std::endl;
        std::cout << std::endl;

        RobotomyRequestForm b("Victim A");
        std::cout << b << std::endl;
        std::cout << std::endl;

        RobotomyRequestForm c(b);
        std::cout << c << std::endl;
        std::cout << std::endl;

        a.setTarget("Victim B");
        b = a;
        std::cout << b << std::endl;
        std::cout << std::endl;

    }
    std::cout << std::endl;
    {
        std::cout << "-----Form Execution Check-----" << std::endl;
        std::srand(std::time(NULL));

        RobotomyRequestForm file1("Victim");
        std::cout << file1 << std::endl;
        std::cout << std::endl;

        Bureaucrat a("A", 150);
        std::cout << a << std::endl;
        a.signForm(file1); // won't be able to sign
        a.executeForm(file1); // shouldn't execute
        std::cout << std::endl;

        Bureaucrat b("B", 70);
        std::cout << b << std::endl;
        b.signForm(file1); // will sign
        b.executeForm(file1); // won't be able to execute
        std::cout << std::endl;
        
        Bureaucrat c("C", 40);
        std::cout << c << std::endl;
        c.signForm(file1); // form is already signed
        c.executeForm(file1); // will execute
        c.executeForm(file1); // can change the result
        c.executeForm(file1); // can change the result
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "-----PRESIDENTIAL PARDON FORM-----" << std::endl;
    std::cout << std::endl;
    {
        std::cout << "-----Orthodox Canonical Form Check-----" << std::endl;
        
        PresidentialPardonForm a;
        std::cout << a << std::endl;
        std::cout << std::endl;

        PresidentialPardonForm b("Victim A");
        std::cout << b << std::endl;
        std::cout << std::endl;

        PresidentialPardonForm c(b);
        std::cout << c << std::endl;
        std::cout << std::endl;

        a.setTarget("Victim B");
        b = a;
        std::cout << b << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "-----Form Execution Check-----" << std::endl;

        PresidentialPardonForm file1("Victim");
        std::cout << file1 << std::endl;
        std::cout << std::endl;

        Bureaucrat a("A", 150);
        std::cout << a << std::endl;
        a.signForm(file1); // won't be able to sign
        a.executeForm(file1); // shouldn't execute
        std::cout << std::endl;

        Bureaucrat b("B", 20);
        std::cout << b << std::endl;
        b.signForm(file1); // will sign
        b.executeForm(file1); // won't be able to execute
        std::cout << std::endl;
        
        Bureaucrat c("C", 1);
        std::cout << c << std::endl;
        c.signForm(file1); // form is already signed
        c.executeForm(file1); // will execute
        std::cout << std::endl;
    }
}