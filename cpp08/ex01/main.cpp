#include "Span.hpp"
#include <iostream>
#include <ctime>

static void sep() { std::cout << "\n----------------------------------------\n"; }

int main()
{
    std::srand(std::time(NULL));
    {   
        sep();
        std::cout << "---Test from Subject---"<< std::endl;
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        std::cout << std::endl;
        std::cout << "---Exception test---"<< std::endl;
        std::cout << "sp: " << sp << std::endl;
        try {
            sp.addNumber(42);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        sep();
        std::cout << "---addNumber overload test---"<< std::endl;
        std::vector<int> src;
        for (int i = 1; i < 10; ++i)
            src.push_back(i * 3);

        Span sp(10);
        try {
            sp.addNumber(src.begin(), src.end());
            std::cout << "sp: " << sp << std::endl;
            std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
            std::cout << "longestSpan:  " << sp.longestSpan()  << "\n";
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        sep();
        std::cout << "---Random numbers test---"<< std::endl;
        const unsigned int N = 10000;
        Span sp(N);

        std::srand(static_cast<unsigned int>(std::time(NULL)));

        for (unsigned int i = 0; i < N; ++i)
            sp.addNumber(std::rand());

        try {
            // std::cout << "sp: " << sp << std::endl;
            std::cout << "shortestSpan: " << sp.shortestSpan() << "\n";
            std::cout << "longestSpan:  " << sp.longestSpan()  << "\n";
        } catch (const std::exception& e) {
            std::cout << "Exception during span calculation: " << e.what() << "\n";
        }
    }
    sep();
}