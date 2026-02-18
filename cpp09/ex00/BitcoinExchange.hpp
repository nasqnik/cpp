// map container

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <map>

#include <cctype> // isdigit
#include <cstdlib> // strtod
#include <cerrno> // errno

#include <exception>

class BitcoinExchange {

    private:
        std::map<std::string, double> _data;
        
        void parseCsv(const std::string& csvPath);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        class FileErrorException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "could not open file.";
                }
        };

        class CorruptedCsvException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "CSV file is corrupted";
                }
        };

        class CorruptedFileException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The file you've provided is corrupted or uses incorrect format";
                }
        };

        void exchange(const std::string& filepath);
};