#include "whatever.hpp"
#include <string>
#include <iostream>

int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    return 0;

}

// int main(void)
// {
//     std::cout << "===== INT TEST =====" << std::endl;

//     int a = 2;
//     int b = 3;
    
//     std::cout << "BEFORE SWAP" << std::endl;
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     ::swap(a, b);
//     std::cout << std::endl;
//     std::cout << "AFTER SWAP" << std::endl;
//     std::cout << "a = " << a << ", b = " << b << std::endl;
//     std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
//     std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
//     std::cout << std::endl;

//     std::cout << "===== STR TEST =====" << std::endl;

//     std::string s1 = "hi";
//     std::string s2 = "hello";

//     std::cout << "BEFORE SWAP" << std::endl;
//     std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
//     ::swap(s1, s2);
//     std::cout << std::endl;
//     std::cout << "AFTER SWAP" << std::endl;
//     std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
//     std::cout << "min(s1, s2) = " << ::min(s1, s2) << std::endl;
//     std::cout << "max(s1, s2) = " << ::max(s1, s2) << std::endl;
// }