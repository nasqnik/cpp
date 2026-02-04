#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <limits>
#include <exception> 
#include <vector>
#include <iterator>
#include <iostream>

class Span 
{
    private:
        unsigned int _capacity;
        std::vector<int> _data;
        Span();

    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int num);

        template <typename T>
        void addNumber(T start, T end) {
            if (_data.size() + std::distance(start, end) > _capacity)
                throw CapacityExceededException();
            _data.insert(_data.end(), start, end);
        }

        long long shortestSpan() const;
        long long longestSpan() const;

        class CapacityExceededException: public std::exception {
            public:
                const char* what() const throw(){
                    return "span: Capacity Exceeded!";
                }
        };
        class NotEnoughNumbersException: public std::exception {
            public:
                const char* what() const throw(){
                    return "span: Not Enough Numbers!";
                }
        };

        std::vector<int> getData() const;
        unsigned int getCapacity() const;
};

std::ostream& operator<<(std::ostream& os, const Span& sp);

#endif