#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data data;
    data.number = 42;
    data.text = "Hello, Serializer";

    uintptr_t raw = Serializer::serialize(&data);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << static_cast<void*>(&data) << std::endl;
    std::cout << "Restored pointer: " << static_cast<void*>(restored) << std::endl;
    std::cout << "raw (uintptr_t)  : " << raw << std::endl;

    if (restored == &data)
        std::cout << "Success: pointers match" << std::endl;
    else
        std::cout << "Error: pointers do NOT match" << std::endl;

    std::cout << "Data contents:" << std::endl;
    std::cout << "number = " << restored->number << std::endl;
    std::cout << "text   = " << restored->text << std::endl;

    restored->number = 1337;
    std::cout << "data.number after change via restored: " << data.number << std::endl;

    return 0;
}
