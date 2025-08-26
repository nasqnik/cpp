#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // AAnimal x; // should not compile: cannot instantiate abstract class (pure virtual makeSound)
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

    // std::cout << std::endl;
    // std::cout << "---Deep copy sanity check (Dog)---" << std::endl;
    // {
    //     Dog basic;
    //     basic.getBrain()->setIdea(0, "Basic idea");
    //     Dog tmp = basic;
    //     tmp.getBrain()->setIdea(0, "TMP idea");
    //     std::cout << "basic[0]: " << basic.getBrain()->getIdea(0) << std::endl;
    //     std::cout << "tmp[0]:   " << tmp.getBrain()->getIdea(0) << std::endl;
    // }

    return 0;
}