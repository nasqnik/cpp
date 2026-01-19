#include "iter.hpp"
#include <iostream>

template <typename T>
void print(T const& x) {
    std::cout << x << std::endl;
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    ::iter(numbers, 5, print);

    std::string words[] = {"Hello", "42", "World"};
    ::iter(words, 3, print);

    return 0;
}