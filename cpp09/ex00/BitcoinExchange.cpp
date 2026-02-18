#include "BitcoinExchange.hpp"

// OCF
BitcoinExchange::BitcoinExchange() {
    parseCsv("data.csv");   
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _data(other._data) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}
    

// parsing

static bool leapYearCheck(const std::string& s) {
    int year;
    int month;
    int day;
    char delimeterOne;
    char delimeterTwo;

    bool isLeapYear = false;
    int monthLength = 31;

    std::istringstream date(s);
    date >> year >> delimeterOne >> month >> delimeterTwo >> day;

    if (date.fail() || !date.eof())
        return false;

    if (month < 1 || month > 12)
        return false;

    if ((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0))
        isLeapYear = true;
    
    if (month == 4 || month == 6 || month == 9 || month == 11)
        monthLength = 30;
    else if (month == 2)
    {
        if (isLeapYear)
            monthLength = 29;
        else
            monthLength = 28;
    }
    
    if (day > monthLength || day < 1)
        return false;
    return true;  
}

static bool isValidDate(const std::string& s) {
    if (s.size() != 10)
        return false;
    if (s[4] != '-' || s[7] != '-')
        return false;
    for (size_t i = 0 ; i < s.size(); i++) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
        if (i == 5)
        {    
            if (s[i] > '1') 
                return false;
            else if (s[i] == '1' && s[i + 1] > '2')
                return false;
        }
        else if (i == 8)
        {
            if (s[i] > '3')
                return false;
            else if (s[i] == '3' && s[i + 1] > '1')
                return false;
        }
    }
    if (!leapYearCheck(s))
        return false;
    return true;
}

static bool convertValue(const std::string& value, double& convertedValue) {
    char *end = NULL;
    errno = 0;

    convertedValue = std::strtod(value.c_str(), &end);
    if (end == value.c_str() || *end != '\0' || errno == ERANGE)
        return false;
    return true;
}

void BitcoinExchange::parseCsv(const std::string& csvPath) {
    std::ifstream inputFile(csvPath.c_str());

    if (!inputFile)
        throw FileErrorException();
    
    std::string line;

    if (!std::getline(inputFile, line) || line != "date,exchange_rate")
        throw CorruptedCsvException();

    while (std::getline(inputFile, line)) {

        if (line.empty())
            throw CorruptedCsvException();

        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos || (line.find(',', commaPos + 1) != std::string::npos))
            throw CorruptedCsvException();
        
        std::string key = line.substr(0, commaPos);
        std::string value = line.substr(commaPos + 1);
        double convertedValue = 0.0;

        if (key.empty() || value.empty() || 
            !isValidDate(key) || !convertValue(value, convertedValue))
            throw CorruptedCsvException();
        
        std::pair<std::map<std::string, double>::iterator, bool> inserted = _data.insert(std::make_pair(key, convertedValue));
        if (!inserted.second)
            throw CorruptedCsvException();
    }

    if (_data.empty())
        throw CorruptedCsvException();
    
    inputFile.close();
}

static bool checkFileHeader(const std::string& header) {
    std::istringstream iss(header);
    std::string date, pipe, value, extra;

    // >> skips extra spaces
    if (!(iss >> date >> pipe >> value))
        return false;
    if (iss >> extra)
        return false;
    return (date == "date" && pipe == "|" && value == "value");
}

void trimSpaces(std::string& str) {
    size_t start = str.find_first_not_of(" ");
    if (start == std::string::npos) {
        str.clear();
        return;
    }
    str.erase(0, start);
    size_t end = str.find_last_not_of(" ");
    str.erase(end + 1);
}

void BitcoinExchange::exchange(const std::string& filepath) {
    std::ifstream inputFile(filepath.c_str());

    if (!inputFile)
        throw FileErrorException();

    std::string line;

    if (!std::getline(inputFile, line) || !checkFileHeader(line))
        throw CorruptedFileException();

    while (std::getline(inputFile, line)) {
        if (line.empty())
            continue;

        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos || (line.find('|', pipePos + 1) != std::string::npos)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
            
        std::string key = line.substr(0, pipePos);
        std::string value = line.substr(pipePos + 1);
        trimSpaces(key);
        trimSpaces(value);

        if (key.empty() || value.empty() || !isValidDate(key)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        double convertedValue = 0.0;
        if (!convertValue(value, convertedValue)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (convertedValue < 0.0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (convertedValue > 1000.0) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        std::map<std::string, double>::const_iterator it = _data.lower_bound(key);
        if (it == _data.end() || it->first != key) {
            if (it == _data.begin()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            --it;
        }
        std::cout << key << " => " << convertedValue << " = "
                  << (convertedValue * it->second) << std::endl;
    }
    inputFile.close();
}