#include "Fixed.hpp"

#include <iostream>

int main( void ) {

    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

// int main( void ) {

//     std::cout << "--- Create a ---" << std::endl;
//     Fixed a;
//     std::cout << std::endl;

//     std::cout << "--- Create b ---" << std::endl;
//     Fixed const b(10);
//     std::cout << std::endl;

//     std::cout << "--- Create c ---" << std::endl;
//     Fixed const c(42.42f);
//     std::cout << std::endl;

//     std::cout << "--- Create d ---" << std::endl;
//     Fixed const d( b );
//     std::cout << std::endl;

//     std::cout << "--- Set a to float value ---" << std::endl;
//     a = Fixed( 1234.4321f );
//     std::cout << std::endl;

//     std::cout << "--- Get values of a, b, c, d ---" << std::endl;
//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Get values of a, b, c, d as integer ---" << std::endl;
//     std::cout << "a is " << a.toInt() << " as integer" << std::endl;
//     std::cout << "b is " << b.toInt() << " as integer" << std::endl;
//     std::cout << "c is " << c.toInt() << " as integer" << std::endl;
//     std::cout << "d is " << d.toInt() << " as integer" << std::endl;
//     std::cout << std::endl;

//     std::cout << "--- Destroy a, b, c, d ---" << std::endl;

//     return 0;
// }