/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:27:26 by anikitin          #+#    #+#             */
/*   Updated: 2025/08/13 16:28:06 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

// int main( void ) 
// {
//     Fixed a;
//     Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
//     std::cout << a << std::endl;
//     std::cout << ++a << std::endl;
//     std::cout << a << std::endl;
//     std::cout << a++ << std::endl;
//     std::cout << a << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
// }

int main(void)
{
    Fixed a(5);
    Fixed b(6.5f);
    
    std::cout << "a:    " << a << std::endl;
    std::cout << "b:    " << b << std::endl;
    std::cout << std::endl;
    
    std::cout << "---Comparison operators test---" << std::endl;
    std::cout << std::boolalpha;
    std::cout << a << " < " << b << ": " << (a < b) << std::endl;
    std::cout << a << " <= " << b << ": " << (a <= b) << std::endl;
    std::cout << a << " = " << b << ": " << (a == b) << std::endl;
    std::cout << a << " > " << b << ": " << (a > b) << std::endl;
    std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
    std::cout << a << " != " << b << ": " << (a != b) << std::endl;
    std::cout << std::noboolalpha;
    std::cout << std::endl;

    std::cout << "---Arithmetic operators test---" << std::endl;

    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << std::endl;

    std::cout << "---Increment/Decrement test---" << std::endl;
    std::cout << "a:    " << a << std::endl;
    std::cout << "++a:  " << ++a << std::endl;
    std::cout << "a:    " << a << std::endl;
    std::cout << "a++:  " << a++ << std::endl;
    std::cout << "a:    " << a << std::endl;
    std::cout << std::endl;
    std::cout << "b:    " << b << std::endl;
    std::cout << "--b:  " << --b << std::endl;
    std::cout << "b:    " << b << std::endl;
    std::cout << "b--:  " << b-- << std::endl;
    std::cout << "b:    " << b << std::endl;
    std::cout << std::endl;

    std::cout << "---Max/min test---" << std::endl;
    std::cout << "a:    " << a << std::endl;
    std::cout << "b:    " << b << std::endl;
    std::cout << "max:  " << Fixed::max( a, b ) << std::endl;
    std::cout << "min:  " << Fixed::min( a, b ) << std::endl;

    Fixed const c(10);
    Fixed const d(6.5f);
    std::cout << "c:    " << c << std::endl;
    std::cout << "d:    " << d << std::endl;
    std::cout << "max:  " << Fixed::max( c, d ) << std::endl;
    std::cout << "min:  " << Fixed::min( c, d ) << std::endl;
    
}