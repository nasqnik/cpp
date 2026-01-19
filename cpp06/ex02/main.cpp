#include "Base.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>

Base* generateA(void) {
    return new classA;
}

Base* generateB(void) {
    return new classB;
}

Base* generateC(void) {
    return new classC;
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
    if (dynamic_cast<classA*>(p))
        std::cout << "class A" << std::endl;
    else if (dynamic_cast<classB*>(p))
        std::cout << "class B" << std::endl;
    else if (dynamic_cast<classC*>(p))
        std::cout << "class C" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<classA&>(p);
        std::cout << "class A" << std::endl;
        return ;
    }
    catch(std::exception& e) {}
    try {
        (void)dynamic_cast<classB&>(p);
        std::cout << "class B" << std::endl;
        return ;
    }
    catch(std::exception& e) {}
    try {
        (void)dynamic_cast<classC&>(p);
        std::cout << "class C" << std::endl;
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
}