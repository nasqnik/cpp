#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>

#include <limits>
#include <iomanip>
#include <cmath>
#include <sstream>

class ScalarConverter {

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

        enum LiteralType {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            ERROR
        };

        static LiteralType detectType(const std::string& str);
        static bool isChar(const std::string& str);
        static bool isFloat(const std::string& str);
        static bool isDouble(const std::string& str);
        static bool isInt(const std::string& str);
        static bool noFraction(double value);

        static double makeDouble(const std::string& str, LiteralType type);

        static void printAll(double value);
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
        static void printError();
        
        static std::string trimOutput(const std::string& s);
        static double roundTo(double v, int decimals);

    public:
        static void convert(const std::string& str);
};

#endif