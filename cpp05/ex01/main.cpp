#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    // {
    //     std::cout << std::endl;
    //     std::cout << "-----Orthodox Canonical Form Check-----" << std::endl;
        
    //     Form a;

    //     std::cout << a << std::endl;
    //     std::cout << std::endl;

    //     Form b("B", 150, 150);
    //     std::cout << b << std::endl;
    //     std::cout << std::endl;

    //     Form c(b);
    //     std::cout << c << std::endl;
    //     std::cout << std::endl;

    //     b = a;
    //     std::cout << b << std::endl;

    // }
    // std::cout << std::endl;
    
    std::cout << std::endl;
    {
        std::cout << "-----Exceptions Check-----" << std::endl;

        try {
            Form a("A", 0, 1);
            std::cout << a << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception form A: " << e.what() << std::endl; 
        }
        std::cout << std::endl;

        try {
            Form b("B", 1, 0);
            std::cout << b << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception form B: " << e.what() << std::endl; 
        }
        std::cout << std::endl;

        try {
            Form c("C", 1, 151);
            std::cout << c << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception form C: " << e.what() << std::endl; 
        }
        std::cout << std::endl;

        try {
            Form d("D", 151, 1);
            std::cout << d << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception form D: " << e.what() << std::endl; 
        }
        std::cout << std::endl;

        try {
            Form ee("E", 1, 1);
            std::cout << ee << std::endl;
            std::cout << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception form E: " << e.what() << std::endl; // shouldn't be an exception
        }
    }
    std::cout << std::endl;
    {
        std::cout << "-----Form Sign Check-----" << std::endl;

        Form f("Form 1", 43, 43);
        std::cout << f << std::endl;
        std::cout << std::endl;

        Bureaucrat a("A", 42);
        std::cout << a << std::endl;
        std::cout << std::endl;

        Bureaucrat b("B", 44);
        std::cout << b << std::endl;
        std::cout << std::endl;

        b.signForm(f);
        a.signForm(f);
        std::cout << std::endl;

        std::cout << f << std::endl;
        std::cout << std::endl;
    }

}