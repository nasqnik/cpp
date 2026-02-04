#include "Span.hpp"

Span::Span(unsigned int N) : _capacity(N), _data() {
    // std::cout << "Span constructor has been called\n";
    _data.reserve(N);
}

Span::Span(const Span& other) : 
    _capacity(other._capacity), _data(other._data) {
    // std::cout << "Span Copy constructor has been called\n";
}

Span& Span::operator=(const Span& other) 
{
    // std::cout << "Span Copy Assignment operator has been called\n";
    if (this != &other) 
    {
        _capacity = other._capacity;
        _data     = other._data;
    }
    return *this;
}

Span::~Span() {
    // std::cout << "Span Destructor has been called\n";
}

void Span::addNumber(int num) 
{
    if (_data.size() >= _capacity)
        throw CapacityExceededException();
    _data.push_back(num);
}

long long Span::longestSpan() const {
    if (_data.size() < 2)
        throw NotEnoughNumbersException();

    long long mn = *std::min_element(_data.begin(), _data.end());
    long long mx = *std::max_element(_data.begin(), _data.end());
    return mx - mn;
}

long long Span::shortestSpan() const 
{
    if (_data.size() < 2)
        throw NotEnoughNumbersException();

    std::vector<int> sorted(_data);
    std::sort(sorted.begin(), sorted.end());

    long long best = std::numeric_limits<long long>::max();

    for (size_t i = 1; i < sorted.size(); ++i) 
    {
        long long d = static_cast<long long>(sorted[i]) - static_cast<long long>(sorted[i - 1]);
        if (d < best) 
            best = d;
        if (best == 0) 
            break;
    }
    return best;
}

std::vector<int> Span::getData() const {
    return _data;
}

unsigned int Span::getCapacity() const {
    return _capacity;
};

std::ostream& operator<<(std::ostream& os, const Span& sp)
{
    os << "[ ";
    std::vector<int> data = sp.getData();

    for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        os << *it;
        std::vector<int>::const_iterator next = it;
        ++next;
        if (next != data.end())
            os << ", ";
    }
    os << " ]";
    os << ", capacity: " << sp.getCapacity();
    return os;
}