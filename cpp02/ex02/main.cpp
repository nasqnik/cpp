#include "Fixed.hpp"

#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
}

// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

//     std::cout << std::boolalpha;
//     std::cout << "Value of a       " << a << std::endl;
//     std::cout << "Value of b       " << b << std::endl;
//     std::cout << "----------COMPARISON---------" << std::endl;
//     std::cout << "a > b:           " << (a > b) << std::endl;
//     std::cout << "a < b:           " << (a < b) << std::endl;
//     std::cout << "a == b:          " << (a == b) << std::endl;
//     std::cout << "a != b:          " << (a != b) << std::endl;
//     std::cout << "a >= b:          " << (a >= b) << std::endl;
//     std::cout << "a <= b:          " << (a <= b) << std::endl;
//     std::cout << "-----INCREMENT/DECREMENT-----" << std::endl;
//     std::cout << "Value of a       " << a << std::endl;
//     std::cout << "Increment ++a    " << ++a << std::endl;
//     std::cout << "Value of a       " << a << std::endl;
//     std::cout << "Increment a++    " << a++ << std::endl;
//     std::cout << "Value of a       " << a << std::endl;
//     std::cout << "----------ARITMETIC----------" << std::endl;
//     std::cout << "a + b:           " << (a + b) << std::endl;
//     std::cout << "a - b:           " << (a - b) << std::endl;
//     std::cout << "b / a:           " << (b / a) << std::endl;
//     std::cout << "a * b:           " << (b * a) << std::endl;
//     std::cout << "-----------MAX/MIN-----------" << std::endl;
//     std::cout << "Print max        " << Fixed::max( a, b ) << std::endl;
//     std::cout << "Print min        " << Fixed::min( a, b ) << std::endl;
// }