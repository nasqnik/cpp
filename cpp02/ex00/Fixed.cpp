#include "Fixed.hpp"


const int Number::_bits = 8;

Number::Number() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Number::Number(const Number& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Number& Number::operator=(const Number& num)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &num)
        this->_value = other._value;
    return *this;
}

Number::~Number() {
    std::cout << "Destructor called" << std::endl;
}

