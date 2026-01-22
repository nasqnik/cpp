#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generateA(void) {
    return new A;
}

Base* generateB(void) {
    return new B;
}

Base* generateC(void) {
    return new C;
}

Base* generate(void) {
    Base* (*generateRandom[3])(void) = {
        &generateA,
        &generateB,
        &generateC,
    };

    int random = rand() % 3;

    return generateRandom[random]();
}

void identify(Base* p) {

    if (!p) {
        std::cout << "Unknown Type\n"; 
        return; 
    }

    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(std::exception& e) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(std::exception& e) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(std::exception& e) {}

    std::cout << "Unknown Type" << std::endl;
}


int main(void) {

    srand(time(NULL));

    Base* pointer = generate();
    Base& reference = *pointer;

    std::cout << "Identifying pointer: ";
    identify(pointer);

    std::cout << "Identifying reference: ";
    identify(reference);

    delete pointer;

    return 0;
}