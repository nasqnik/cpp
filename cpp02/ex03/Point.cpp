#include "Point.hpp"

Point::Point() {};

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {};

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::~Point() {};

Fixed Point::getX() const
{
    return _x;
}

Fixed Point::getY() const
{
    return _y;
}