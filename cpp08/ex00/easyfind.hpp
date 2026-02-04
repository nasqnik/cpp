#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <algorithm>


class ValueNotFoundException: public std::exception {
    public:
        const char* what() const throw(){
            return "easyfind: Value not found!";
        }
};

template <typename T>
typename T::iterator easyfind(T& container, int num) {
    typename T::iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T& container, int num) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
        throw ValueNotFoundException();
    return it;
}

#endif