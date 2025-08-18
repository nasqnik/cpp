#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Bureaucrat creation tests ===" << std::endl;
    try {
        Bureaucrat a("Alice", 42);
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception creating Alice: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b("Bob", 0); // invalid
    } catch (const std::exception& e) {
        std::cerr << "Exception creating Bob: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 151); // invalid
    } catch (const std::exception& e) {
        std::cerr << "Exception creating Charlie: " << e.what() << std::endl;
    }

    std::cout << "\n=== Form creation tests ===" << std::endl;
    try {
        Form f1("Form42", 75, 100);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception creating Form42: " << e.what() << std::endl;
    }

    try {
        Form f2("InvalidForm", 0, 10); // invalid
    } catch (const std::exception& e) {
        std::cerr << "Exception creating InvalidForm: " << e.what() << std::endl;
    }

    try {
        Form f3("InvalidForm2", 151, 10); // invalid
    } catch (const std::exception& e) {
        std::cerr << "Exception creating InvalidForm2: " << e.what() << std::endl;
    }

    std::cout << "\n=== Signing tests ===" << std::endl;
    Bureaucrat high("HighRank", 10);
    Bureaucrat low("LowRank", 140);
    Form important("TopSecret", 50, 20);
    Form easy("SimpleForm", 145, 120);

    std::cout << high << std::endl;
    std::cout << low << std::endl;
    std::cout << important << std::endl;
    std::cout << easy << std::endl;

    std::cout << "\n-- High tries to sign TopSecret --" << std::endl;
    high.signForm(important);
    std::cout << important << std::endl;

    std::cout << "\n-- Low tries to sign TopSecret --" << std::endl;
    low.signForm(important);
    std::cout << important << std::endl;

    std::cout << "\n-- Low tries to sign SimpleForm --" << std::endl;
    low.signForm(easy);
    std::cout << easy << std::endl;

    return 0;
}