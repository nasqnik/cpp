#include "easyfind.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <set>

static void sep() { std::cout << "\n----------------------------------------\n"; }

struct PrintInt
{
    void operator()(int x) const { 
        std::cout << x << " "; 
    }
};

template <typename T>
void printContainer(const T& container, const std::string& name)
{
    std::cout << name << ": ";
    std::for_each(container.begin(), container.end(), PrintInt());
    std::cout << "\n";
}

int main()
{
    {
        sep();
        std::cout << "---Vector test---"<< std::endl;

        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(20);

        printContainer(v, "v");
        try {
            std::vector<int>::iterator it = easyfind(v, 20);
            int position = it - v.begin();
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
        std::cout << std::endl;
        try {
            std::cout << "Trying to find 999 in v..." << std::endl;
            std::vector<int>::iterator it = easyfind(v, 999);
            int position = it - v.begin();
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
        std::cout << std::endl;
        std::cout << "---Const Vector test---"<< std::endl;

        std::cout << std::endl;
        const std::vector<int> constV = v;
        printContainer(constV, "constV");
        try {
            std::vector<int>::const_iterator it = easyfind(constV, 30);
            int position = it - constV.begin();
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
        std::cout << std::endl;
        try {
            std::cout << "Trying to find 111 in constV..." << std::endl;
            std::vector<int>::const_iterator it = easyfind(constV, 111);
            int position = it - constV.begin();
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
    }

    {
        sep();
        std::cout << "---List test---" << std::endl;

        std::list<int> l;
        l.push_back(5);
        l.push_back(6);
        l.push_back(7);
        l.push_back(8);

        printContainer(l, "l");

        try {
            std::list<int>::iterator it = easyfind(l, 7);
            int position = std::distance(l.begin(), it);
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
        std::cout << std::endl;
        try {
            std::cout << "Trying to find 100 in l..." << std::endl;
            std::list<int>::iterator it = easyfind(l, 100);
            int position = std::distance(l.begin(), it);
            std::cout << "Found value: " << *it << " at index " << position << "\n";
        }
        catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << "\n";
        }
    }
    sep();
    return 0;
}