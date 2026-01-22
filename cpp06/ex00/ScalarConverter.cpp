#include "ScalarConverter.hpp"

// Orthodox Canonical Form

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}
        
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// Convert function
        
void ScalarConverter::convert(const std::string& str) {

    LiteralType type = detectType(str);

    if (type == ERROR) 
        return printError();

    double value = makeDouble(str, type);

    printAll(value);
}

// Detect Type

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& str) {
    if (str.empty())
        return ERROR;
        
    if (isChar(str))
        return CHAR;
    if (isInt(str))
        return INT;
    if (isFloat(str))
        return FLOAT;
    if (isDouble(str))
        return DOUBLE;

    return ERROR;
} 

bool ScalarConverter::isChar(const std::string& str) {
    if (str.length() != 1)
        return false;
    return std::isdigit(static_cast<unsigned char>(str[0])) == 0;
}

bool ScalarConverter::isInt(const std::string& str) {

    char *end = 0;
    errno = 0;

    long i = std::strtol(str.c_str(), &end, 10);

    if (end == str.c_str() || *end != '\0')
        return false;
    if (errno == ERANGE)
        return false;
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str == "nanf" || str == "inff" || str == "+inff" || str == "-inff")
        return true;

    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;
    
    std::string f = str.substr(0, str.length() - 1);

    char *end = 0;
    errno = 0;

    std::strtod(f.c_str(), &end);

    return end != f.c_str() && *end == '\0';
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str == "nan" || str == "inf" || str == "+inf" || str == "-inf")
        return true;

    char *end = 0;
    errno = 0;
    std::strtod(str.c_str(), &end);

    return end != str.c_str() && *end == '\0';
}

bool ScalarConverter::noFraction(double v) {

    if (isNan(v) || isInf(v))
        return false;

    double valNoFraction;
    return std::modf(v, &valNoFraction) == 0.0;
}

bool ScalarConverter::isNan(double x) { 
    return x != x; 
}

bool ScalarConverter::isInf(double x) { 
    return x == std::numeric_limits<double>::infinity()
            || x == -std::numeric_limits<double>::infinity(); 
}

double ScalarConverter::makeDouble(const std::string& str, ScalarConverter::LiteralType type) {

    if (str == "nanf" || str == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    if (str == "-inff" || str == "-inf")
        return -std::numeric_limits<double>::infinity();
    if (str == "inff" || str == "+inff" || str == "inf" || str == "+inf")
        return std::numeric_limits<double>::infinity();

    if (type == CHAR)
        return static_cast<double>(str[0]);

    if (type == INT) {
        long val = std::strtol(str.c_str(), 0, 10);
        return static_cast<double>(val);
    }

    std::string s = str;

    if (type == FLOAT)
        s = str.substr(0, str.length() - 1);

    return std::strtod(s.c_str(), 0);
}

void ScalarConverter::printAll(double value) {
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";

    if (isNan(value) || isInf(value) || !noFraction(value) ||
        value < 0.0 || value > 127.0)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    unsigned char c = static_cast<unsigned char>(value);

    if (!std::isprint(c)) 
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(c) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {

    std::cout << "int: ";

    if (isNan(value) || isInf(value) || !noFraction(value) ||
        value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "impossible" << std::endl;
        return ;
    }

    std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {

    std::cout << "float: ";

    if (isNan(value)) {
        std::cout << "nanf" << std::endl;
        return;
    }
    if (isInf(value)) {
        if (value < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
        return;
    }

    double rounded = roundTo(value, 6);
    float f = static_cast<float>(rounded);

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(7) << f;

    std::cout << trimOutput(oss.str()) << "f" << std::endl;
}


void ScalarConverter::printDouble(double value) {

    std::cout << "double: ";

    if (isNan(value)) {
        std::cout << "nan" << std::endl;
        return;
    }
    if (isInf(value)) {
        if (value < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "+inf" << std::endl;
        return;
    }

    if (noFraction(value)) {
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
        return;
    }

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(7) << value;

    std::cout << trimOutput(oss.str()) << std::endl;
}

void ScalarConverter::printError() {
    std::cerr << "char: impossible" << std::endl;
    std::cerr << "int: impossible" << std::endl;
    std::cerr << "float: impossible" << std::endl;
    std::cerr << "double: impossible" << std::endl;
}


std::string ScalarConverter::trimOutput(const std::string& s) {

    std::string out = s;

    std::string::size_type dot = out.find('.');
    if (dot == std::string::npos)
        return out;

    while (!out.empty() && out[out.size() - 1] == '0')
        out.erase(out.size() - 1);

    if (!out.empty() && out[out.size() - 1] == '.')
        out.erase(out.size() - 1);
    
    if (out.find('.') == std::string::npos)
        out += ".0";

    return out;
}

double ScalarConverter::roundTo(double v, int decimals) {
    double factor = std::pow(10.0, decimals);
    return std::floor(v * factor + 0.5) / factor;
}