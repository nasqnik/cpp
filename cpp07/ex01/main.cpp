#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

void increment(int &x) {
    x++;
}

void to_upper(std::string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 'a' + 'A';
    }
}

int main(void) {
    std::cout << "---int array: print---" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    ::iter(numbers, 5, print<int>);

    std::cout << "---int array: increment and print---" << std::endl;
    ::iter(numbers, 5, increment);
    ::iter(numbers, 5, print<int>);

    std::cout << "---const int array: print (must use const overload)---" << std::endl;
    const int cnumbers[] = {10, 20, 30};
    ::iter(cnumbers, 3, print<int>);

    std::cout << "---string array: print, then mutate to upper---" << std::endl;
    std::string words[] = {"Hello", "42", "World"};
    ::iter(words, 3, print<std::string>);
    ::iter(words, 3, to_upper);
    ::iter(words, 3, print<std::string>);

    return 0;
}
