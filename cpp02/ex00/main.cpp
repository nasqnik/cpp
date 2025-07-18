#include "Fixed.hpp"

#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}

// int main( void ) 
// {
//     std::cout << "--- Create a ---" << std::endl;
//     Fixed a;
//     std::cout << std::endl;

//     std::cout << "--- Create b ---" << std::endl;
//     Fixed b(a);
//     std::cout << std::endl;

//     std::cout << "--- Create c ---" << std::endl;
//     Fixed c;
//     c = b;
//     std::cout << std::endl;
    
//     std::cout << "--- Set a, b, c ---" << std::endl;
//     a.setRawBits(10);
//     b.setRawBits(20);
//     c.setRawBits(30);
//     std::cout << std::endl;

//     std::cout << "--- Get values of a, b, c ---" << std::endl;
//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Destroy a, b, c ---" << std::endl;

//     return 0;
// }