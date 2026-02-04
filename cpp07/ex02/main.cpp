#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

static void sep() {
    std::cout << "\n----------------------------------------\n";
}

int main() {
    std::cout << "Tests\n";

    // Default constructor
    sep();
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << " (expected 0)\n";

    // Sized constructor + read/write
    sep();
    Array<int> a(4);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i) * 10;
    std::cout << "a values (expected 0 10 20 30): ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";

    // Out of bounds throws
    sep();
    try {
        std::cout << "Access a[4]...\n";
        (void)a[4];
        std::cout << "ERROR: no exception thrown\n";
    } catch (const std::exception &e) {
        std::cout << "OK: caught exception: " << e.what() << "\n";
    }

    // Copy constructor deep copy
    sep();
    Array<int> b(a);
    a[0] = 999;
    std::cout << "After changing a[0]=999:\n";
    std::cout << "a[0] = " << a[0] << "\n";
    std::cout << "b[0] = " << b[0] << " (should NOT be 999)\n";

    // Assignment operator deep copy + different size
    sep();
    Array<int> c(2);
    c[0] = 1; c[1] = 2;
    c = a; 
    a[1] = 777;
    std::cout << "After c=a and changing a[1]=777:\n";
    std::cout << "a[1] = " << a[1] << "\n";
    std::cout << "c[1] = " << c[1] << " (should NOT be 777)\n";
    std::cout << "c.size() = " << c.size() << " (should be " << a.size() << ")\n";

    // Const operator[]
    sep();
    const Array<int> ca(a);
    std::cout << "const ca[2] = " << ca[2] << "\n";
    try {
        std::cout << "Access ca[99]...\n";
        (void)ca[99];
        std::cout << "ERROR: no exception thrown\n";
    } catch (const std::exception &e) {
        std::cout << "OK: caught exception: " << e.what() << "\n";
    }

    // Different types
    sep();
    Array<std::string> s(2);
    s[0] = "Hello";
    s[1] = "42";
    std::cout << "strings: " << s[0] << " " << s[1] << "\n";

    sep();
    std::cout << "Done.\n";
    return 0;
}
