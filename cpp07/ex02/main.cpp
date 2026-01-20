#include <iostream>
#include <stdexcept>
#include <string>

#include "Array.hpp"

#define SEP() std::cout << "\n----------------------------------------\n"

static void test_default_constructor()
{
    SEP();
    std::cout << "[Test] Default constructor\n";

    Array<int> a;
    std::cout << "size: " << a.size() << "\n";
    std::cout << "Expected: 0\n";
}

static void test_sized_constructor_default_init()
{
    SEP();
    std::cout << "[Test] Sized constructor + default initialization\n";

    Array<int> a(5);
    std::cout << "size: " << a.size() << "\n";
    std::cout << "Values (expect all 0): ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";

    Array<std::string> s(3);
    std::cout << "string size: " << s.size() << "\n";
    std::cout << "Values (expect empty strings): ";
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << "\"" << s[i] << "\"" << (i + 1 < s.size() ? " " : "");
    std::cout << "\n";
}

static void test_subscript_read_write()
{
    SEP();
    std::cout << "[Test] operator[] read/write\n";

    Array<int> a(4);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i) * 10;

    std::cout << "Values (expect 0 10 20 30): ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";
}

static void test_out_of_bounds()
{
    SEP();
    std::cout << "[Test] operator[] out of bounds throws\n";

    Array<int> a(2);

    try {
        std::cout << "Access a[2]...\n";
        (void)a[2];
        std::cout << "ERROR: No exception thrown\n";
    } catch (const std::exception& e) {
        std::cout << "OK: Caught exception: " << e.what() << "\n";
    }

    try {
        std::cout << "Access a[999]...\n";
        (void)a[999];
        std::cout << "ERROR: No exception thrown\n";
    } catch (const std::exception& e) {
        std::cout << "OK: Caught exception: " << e.what() << "\n";
    }
}

static void test_copy_constructor_deep_copy()
{
    SEP();
    std::cout << "[Test] Copy constructor deep copy\n";

    Array<int> a(3);
    a[0] = 1; a[1] = 2; a[2] = 3;

    Array<int> b(a); // copy

    // Modify original; copy must not change
    a[1] = 42;

    std::cout << "Original a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";

    std::cout << "Copy     b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << (i + 1 < b.size() ? " " : "");
    std::cout << "\n";

    std::cout << "Expected b to remain: 1 2 3\n";
}

static void test_assignment_operator_deep_copy()
{
    SEP();
    std::cout << "[Test] Assignment operator deep copy\n";

    Array<int> a(4);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i + 1); // 1 2 3 4

    Array<int> b;      // empty
    b = a;             // assign

    // Modify assigned-to and original independently
    a[0] = 99;
    b[3] = -7;

    std::cout << "Original a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";

    std::cout << "Assigned b: ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << (i + 1 < b.size() ? " " : "");
    std::cout << "\n";

    std::cout << "Expected: a[0] changed doesn't affect b, and b[3] changed doesn't affect a\n";
}

static void test_assignment_self()
{
    SEP();
    std::cout << "[Test] Self-assignment safety\n";

    Array<int> a(3);
    a[0] = 5; a[1] = 6; a[2] = 7;

    a = a; // should do nothing harmful

    std::cout << "After self-assign a: ";
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << (i + 1 < a.size() ? " " : "");
    std::cout << "\n";
    std::cout << "Expected: 5 6 7\n";
}

static void test_const_access()
{
    SEP();
    std::cout << "[Test] Const operator[]\n";

    Array<int> tmp(2);
    tmp[0] = 11;
    tmp[1] = 22;

    const Array<int> a(tmp);

    std::cout << "Const read a[0], a[1]: " << a[0] << " " << a[1] << "\n";
    std::cout << "Expected: 11 22\n";

    try {
        std::cout << "Const out-of-bounds a[2]...\n";
        (void)a[2];
        std::cout << "ERROR: No exception thrown\n";
    } catch (const std::exception& e) {
        std::cout << "OK: Caught exception: " << e.what() << "\n";
    }
}

static void test_assign_different_sizes()
{
    SEP();
    std::cout << "[Test] Assignment between different sizes\n";

    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); i++)
        a[i] = static_cast<int>(i);

    Array<int> b(2);
    b[0] = 100;
    b[1] = 200;

    b = a; // b should resize to 5 and copy values

    std::cout << "b size after assign: " << b.size() << "\n";
    std::cout << "b values (expect 0 1 2 3 4): ";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << (i + 1 < b.size() ? " " : "");
    std::cout << "\n";
}

int main()
{
    std::cout << "CPP07 ex02 - Array template tests\n";

    test_default_constructor();
    test_sized_constructor_default_init();
    test_subscript_read_write();
    test_out_of_bounds();
    test_copy_constructor_deep_copy();
    test_assignment_operator_deep_copy();
    test_assignment_self();
    test_const_access();
    test_assign_different_sizes();

    SEP();
    std::cout << "Done.\n";
    return 0;
}
