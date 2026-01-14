#include "Bureaucrat.hpp"

int main(void)
{
    // std::cout << std::endl;
    // std::cout << "-----Orthodox Canonical Form Check-----" << std::endl;
    
    // Bureaucrat a;

    // std::cout << a << std::endl;
    // std::cout << std::endl;

    // Bureaucrat b("b", 50);
    // std::cout << b << std::endl;
    // std::cout << std::endl;

    // Bureaucrat c(b);
    // std::cout << c << std::endl;
    // std::cout << std::endl;

    // b = a;
    // std::cout << b << std::endl;

    std::cout << std::endl;
    std::cout << "-----Exceptions Check-----" << std::endl;

    try {
        std::cout << std::endl;
        Bureaucrat f("F", 42);
        std::cout << f << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception bureaucrat F: " << e.what() << std::endl;
    }

    try {
        Bureaucrat d("D", 151);
        std::cout << d << std::endl;
        std::cout << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception bureaucrat D: " << e.what() << std::endl;
    }

    try {
        std::cout << std::endl;
        Bureaucrat ee("E", 0);
        std::cout << ee << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception bureaucrat E: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "-----Increment/Decrement Check-----" << std::endl;
    std::cout << std::endl;
    try {
        Bureaucrat g("G", 150);
        std::cout << g << std::endl;
        g.decrementGrade();
        std::cout << "After decrement: " << g << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Decrement exception for G: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat h("H", 1);
        std::cout << h << std::endl;
        h.incrementGrade();
        std::cout << "After increment: " << h << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Increment exception for H: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        Bureaucrat i("I", 42);
        std::cout << i << std::endl;
        i.incrementGrade();
        std::cout << "After increment: " << i << std::endl;
        i.decrementGrade();
        std::cout << "After decrement: " << i << std::endl;
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Increment/Decrement exception for I: " << e.what() << std::endl;
    }
    return 0;
}