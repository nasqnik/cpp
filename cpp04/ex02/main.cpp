#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    AAnimal *array[4];

    std::cout << "---Create 2 Dogs with brains---" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "🐶 Dog " << (i + 1) << std::endl;
        array[i] = new Dog();
        std::cout << std::endl;
    }

    std::cout << "---Create 2 Cats with brains---" << std::endl;
    for (int i = 2; i < 4; i++)
    {
        std::cout << "🐱 Cat " << (i - 1) << std::endl;
        array[i] = new Cat();
        std::cout << std::endl;
    }

    std::cout << "---Make everyone speak---" << std::endl;
    for (int i = 0; i < 4; ++i)
    {
        std::cout << "Animal type: " << array[i]->getType() << " : ";
        array[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "---Clean up all---" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete array[i];

    return 0;
}