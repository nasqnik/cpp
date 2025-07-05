#include "Point.hpp"

static Fixed area(Point const a, Point const b, Point const c)
{
    return Fixed(
        (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
        + b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
        + c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) 
        / 2.0f
    );
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = area(a, b, c);
    Fixed areaPAB = area(point, a, b);
    Fixed areaPBC = area(point, b, c);
    Fixed areaPCA = area(point, c, a);

    if (areaPAB == 0 || areaPBC == 0 || areaPCA == 0)
        return false;

    Fixed sum = areaPAB + areaPBC + areaPCA;

    return (sum == areaABC);
}