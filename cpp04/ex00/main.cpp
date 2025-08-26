#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "---NORMAL ANIMAL TESTS---" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << std::endl;

    std::cout << j->getType() << " sounds:      ";
    j->makeSound();
    std::cout << i->getType() << " sounds:      ";
    i->makeSound();
    std::cout << meta->getType() << " sounds:   ";
    meta->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "---WRONG ANIMAL TESTS---" << std::endl;
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* b = new WrongCat();
    std::cout << std::endl;

    std::cout << a->getType() << " sounds:   ";
    a->makeSound();
    std::cout << b->getType() << " sounds:      ";
    b->makeSound();
    std::cout << std::endl;

    WrongCat directWrongCat;
    std::cout << "Direct WrongCat sounds: ";
    directWrongCat.makeSound();
    std::cout << std::endl;

    delete a;
    delete b;

    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::cout << std::endl;

    // std::cout << "---ADDITIONAL TESTS---" << std::endl;
    // std::cout << std::endl;
    // std::cout << "---Animal Tests---" << std::endl;
    // Animal animal1;
    // Animal animal2(animal1);
    // Animal animal3 = animal2;
    // std::cout << "animal1 sounds: ";
    // animal1.makeSound();
    // std::cout << "animal2 sounds: ";
    // animal2.makeSound();
    // std::cout << "animal2 sounds: ";
    // animal3.makeSound();
    // std::cout << std::endl;

    // std::cout << "---Cat Tests---" << std::endl;
    // Cat cat1;
    // Cat cat2(cat1);
    // Cat cat3 = cat2;
    // std::cout << std::endl;

    // std::cout << cat1.getType() << "1 sounds: ";
    // cat1.makeSound();
    // std::cout << cat2.getType() << "2 sounds: ";
    // cat2.makeSound();
    // std::cout << cat3.getType() << "3 sounds: ";
    // cat3.makeSound();
    // std::cout << std::endl;

    // std::cout << "---Dog Tests---" << std::endl;
    // Dog dog1;
    // Dog dog2(dog1);
    // Dog dog3 = dog2;
    // std::cout << std::endl;

    // std::cout << dog1.getType() << "1 sounds: ";
    // dog1.makeSound();
    // std::cout << dog2.getType() << "2 sounds: ";
    // dog2.makeSound();
    // std::cout << dog3.getType() << "3 sounds: ";
    // dog3.makeSound();
    // std::cout << std::endl;

    // std::cout << "---WrongAnimal Tests---" << std::endl;
    // WrongAnimal wrongAnimal1;
    // WrongAnimal wrongAnimal2(wrongAnimal1);
    // WrongAnimal wrongAnimal3 = wrongAnimal2;
    // std::cout << std::endl;

    // std::cout << wrongAnimal1.getType() << "1 sounds: ";
    // wrongAnimal1.makeSound();
    // std::cout << wrongAnimal2.getType() << "2 sounds: ";
    // wrongAnimal2.makeSound();
    // std::cout << wrongAnimal3.getType() << "3 sounds: ";
    // wrongAnimal3.makeSound();
    // std::cout << std::endl;

    // std::cout << "---WrongCat Tests---" << std::endl;
    // WrongCat wrongCat1;
    // WrongCat wrongCat2(wrongCat1);
    // WrongCat wrongCat3 = wrongCat2;
    // std::cout << std::endl;

    // std::cout << wrongCat1.getType() << "1 sounds: ";
    // wrongCat1.makeSound();
    // std::cout << wrongCat2.getType() << "2 sounds: ";
    // wrongCat2.makeSound();
    // std::cout << wrongCat3.getType() << "3 sounds: ";
    // wrongCat3.makeSound();
    // std::cout << std::endl;

    // std::cout << "---Clean upppp---" << std::endl;

    return 0;
}