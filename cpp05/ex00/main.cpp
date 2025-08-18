#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "--- Bureaucrat A ---" << std::endl;
    try {
        Bureaucrat a("A", 42);
        std::cout << a << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--- Bureaucrat B ---" << std::endl;
    try {
        Bureaucrat b("B", 0);
        std::cout << b << std::endl;
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception while creating B: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--- Bureaucrat C ---" << std::endl;
    try {
        Bureaucrat c("C", 151);
        std::cout << c << std::endl;
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception while creating C: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--- Bureaucrat D ---" << std::endl;
    try {
        Bureaucrat d("D", 2);
        std::cout << d << std::endl;
        d.incrementGrade();
        std::cout << "After increment: " << d << std::endl;
        d.incrementGrade();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception while incrementing D: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << "--- Bureaucrat E ---" << std::endl;
    try {
        Bureaucrat e("E", 149);
        std::cout << e << std::endl;
        e.decrementGrade();
        std::cout << "After decrement: " << e << std::endl;
        e.decrementGrade();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception while decrementing E: " << e.what() << std::endl;
    }

    // Additional test cases
    std::cout << "--- Testing Edge Cases ---" << std::endl;
    try {
        Bureaucrat edge1("Edge1", 1);
        std::cout << edge1 << std::endl;
        edge1.incrementGrade(); // Should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception for grade 1 increment: " << e.what() << std::endl;
    }
    
    try {
        Bureaucrat edge150("Edge150", 150);
        std::cout << edge150 << std::endl;
        edge150.decrementGrade(); // Should throw exception
    } catch (const std::exception& e) {
        std::cerr << "Exception for grade 150 decrement: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Testing Copy Operations ---" << std::endl;
    try {
        Bureaucrat original("Original", 50);
        std::cout << "Original: " << original << std::endl;
        
        Bureaucrat copy1(original); // Copy constructor
        std::cout << "Copy1 (copy constructor): " << copy1 << std::endl;
        
        Bureaucrat copy2("Temp", 25);
        std::cout << "Copy2 before assignment: " << copy2 << std::endl;
        copy2 = original; // Copy assignment
        std::cout << "Copy2 after assignment: " << copy2 << std::endl;
        
        // Test that copies are independent
        original.incrementGrade();
        std::cout << "After incrementing original: " << original << std::endl;
        std::cout << "Copy1 unchanged: " << copy1 << std::endl;
        std::cout << "Copy2 unchanged: " << copy2 << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Exception in copy operations: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Testing Multiple Operations ---" << std::endl;
    try {
        Bureaucrat multi("Multi", 10);
        std::cout << "Starting grade: " << multi << std::endl;
        
        for (int i = 0; i < 5; i++) {
            multi.incrementGrade();
            std::cout << "After increment " << (i+1) << ": " << multi << std::endl;
        }
        
        for (int i = 0; i < 5; i++) {
            multi.decrementGrade();
            std::cout << "After decrement " << (i+1) << ": " << multi << std::endl;
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Exception in multiple operations: " << e.what() << std::endl;
    }

    return 0;
}