/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anikitin <anikitin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 16:27:37 by anikitin          #+#    #+#             */
/*   Updated: 2025/08/14 14:28:02 by anikitin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int value)
{
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = static_cast<int>(roundf(floatValue * (1 << _fractionalBits)));
}

Fixed& Fixed::operator=(const Fixed& num)
{
    // std::cout << "Copy assignment operator called" << std::endl;

    if (this != &num)
        this->_rawBits = num._rawBits;
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
}


// ----------COMPARISON OPERATORS----------

bool  Fixed::operator>(const Fixed &other) const
{
    return this->_rawBits > other._rawBits;
}

bool  Fixed::operator<(const Fixed &other) const
{
    return this->_rawBits < other._rawBits;
}

bool  Fixed::operator>=(const Fixed &other) const
{
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed &other) const
{   
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed &other) const
{   
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{   
    return this->_rawBits != other._rawBits;
}


// ----------ARITHMETIC OPERATORS----------

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;

    result._rawBits = (this->_rawBits * other._rawBits) >> result._fractionalBits;
    return result;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;

    result._rawBits = this->_rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;

    result._rawBits = this->_rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;

    if (other._rawBits == 0)
    {
        std::cerr << "Error: division by zero" << std::endl;
        return Fixed();
    }
    result._rawBits = (this->_rawBits << result._fractionalBits) / other._rawBits;
    return result;
}

// ----------INCREMENT/DECREMENT OPERATORS----------

Fixed& Fixed::operator++()
{
    ++this->_rawBits;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed& Fixed::operator--()
{
    --this->_rawBits;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}


// ----------MIN/MAX OPERATORS----------

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a:b);
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a:b);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a:b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a:b);
}


int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
    _rawBits = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
