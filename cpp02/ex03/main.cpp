#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

int main( void ) 
{
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    Point insidePoint(2.0f, 2.0f);
    Point outsidePoint(20.0f, 2.0f);
    Point edgePoint(0.0f, 0.0f);

    std::cout << "insidePoint is inside? " << (bsp(a, b, c, insidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "outsidePoint is inside? " << (bsp(a, b, c, outsidePoint) ? "Yes" : "No") << std::endl;
    std::cout << "edgePoint is inside? " << (bsp(a, b, c, edgePoint) ? "Yes" : "No") << std::endl;

    return 0;
}