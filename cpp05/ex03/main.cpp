#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    std::cout << std::endl;

    Intern i;
    Bureaucrat a("A", 1);

    std::cout << std::endl;
    std::cout << "-----Unknown Form-----" << std::endl;
    try {
        AForm* form1 = i.makeForm("unknown", "Victim1");
        std::cout << std::endl;
        delete form1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-----Shrubbery Creation Form-----" << std::endl;
    try {
        AForm* form2 = i.makeForm("shrubbery creation", "tree");

        std::cout << std::endl;
        form2->beSigned(a);
        form2->execute(a);
        std::cout << std::endl;
        delete form2;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-----Robotomy Request Form-----" << std::endl;
    try {
        AForm* form3 = i.makeForm("robotomy request", "Victim2");
        std::cout << std::endl;
        form3->beSigned(a);
        form3->execute(a);
        std::cout << std::endl;
        delete form3;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "-----Presidential Pardon Form-----" << std::endl;
    try {
        AForm* form4;

        form4 = i.makeForm("presidential pardon", "Victim3");
        std::cout << std::endl;
        form4->beSigned(a);
        form4->execute(a);
        std::cout << std::endl;
        delete form4;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
    
}