#include "Serializer.hpp"

#include <iostream>

int main(void) {
    
    Data data;
    data.number = 42;
    data.text = "Hello, Serializer";

    uintptr_t raw = Serializer::serialize(&data);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer:  " << &data << std::endl;
    std::cout << "Restored pointer:  " << restored << std::endl;

    if (restored == &data)
        std::cout << "Success: pointers match" << std::endl;
    else
        std::cout << "Error: pointers do NOT match" << std::endl;

    std::cout << "Data contents:" << std::endl;
    std::cout << "number = " << restored->number << std::endl;
    std::cout << "text   = " << restored->text << std::endl;

    return 0;
};