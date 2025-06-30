#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Number
{
    private:
        int _value;
        static const int    _bits;

    public:
        Number();
        Number(const Number& other);
        Number& operator=(const Number& other);
        ~Number();

};

#endif