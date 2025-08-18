#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *array[4];

    std::cout << "---Create 2 Dogs with brains---" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        std::cout << "🐶 Dog " << std::to_string(i + 1) << std::endl;
        array[i] = new Dog();
        std::cout << std::endl;
    }

    std::cout << "---Create 2 Cats with brains---" << std::endl;
    for (int i = 2; i < 4; i++)
    {
        std::cout << "🐱 Cat " << std::to_string(i - 1) << std::endl;
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

    std::cout << "---Put some ideas into dog's brains---" << std::endl;
    Dog* dog = dynamic_cast<Dog*>(array[0]);
    dog->getBrain()->setIdea(0, "I am a dog and I'm hungry. Woof~");
    dog->getBrain()->setIdea(99, "Final dog thought.");
    std::cout << "🐶 Dog 1 Idea:       " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "🐶 Dog 1 Idea[99]:   " << dog->getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;

    Dog dog2(*dog);
    std::cout << std::endl;
    std::cout << "🐶 Dog 2 Idea:       " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐶 Dog 2 Idea[99]:   " << dog2.getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;
    Dog dog3;
    dog3 = *dog;
    std::cout << std::endl;
    std::cout << "🐶 Dog 3 Idea:       " << dog3.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "---Change original dog idea---" << std::endl;
    dog->getBrain()->setIdea(0, "No, now I want a bone!");
    std::cout << "🐶 Dog 1 Idea after change:                  " << dog->getBrain()->getIdea(0) << std::endl;
    std::cout << "🐶 Dog 1 Idea[99] should be unchanged:       " << dog->getBrain()->getIdea(99) << std::endl;
    std::cout << "🐶 Dog 2 Idea should be unchanged:           " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐶 Dog 2 Idea[99] should be unchanged:       " << dog2.getBrain()->getIdea(99) << std::endl;
    std::cout << "🐶 Dog 3 Idea should be unchanged:           " << dog3.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "---Put some ideas into cat's brains---" << std::endl;
    Cat* cat = dynamic_cast<Cat*>(array[2]);
    cat->getBrain()->setIdea(0, "I am a cat and I want to be left alone. Meow~");
    cat->getBrain()->setIdea(99, "No final thoughts for a cat.");
    std::cout << "🐱 Cat 1 Idea:       " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "🐱 Cat 1 Idea[99]:   " << cat->getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;

    Cat cat2(*cat);
    std::cout << std::endl;
    std::cout << "🐱 Cat 2 Idea:       " << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐱 Cat 2 Idea[99]:   " << cat2.getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;
    Cat cat3;
    cat3 = *cat;
    std::cout << std::endl;
    std::cout << "🐱 Cat 3 Idea:       " << cat3.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    std::cout << "---Change original cat idea---" << std::endl;
    cat->getBrain()->setIdea(0, "No, I want to be petted! Purrrrrrr...");
    std::cout << "🐱 Cat 1 Idea after change:              " << cat->getBrain()->getIdea(0) << std::endl;
    std::cout << "🐱 Cat 1 Idea[99] should be unchanged:   " << cat->getBrain()->getIdea(99) << std::endl;
    std::cout << "🐱 Cat 2 Idea should be unchanged:       " << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐱 Cat 2 Idea[99] should be unchanged:   " << cat2.getBrain()->getIdea(99) << std::endl;
    std::cout << "🐱 Cat 3 Idea should be unchanged:       " << cat3.getBrain()->getIdea(0) << std::endl;
    std::cout << "🐱 Cat 3 Idea[99] should be unchanged:   " << cat3.getBrain()->getIdea(99) << std::endl;
    std::cout << std::endl;


    std::cout << "---Clean up all---" << std::endl;
    for (int i = 0; i < 4; ++i)
        delete array[i];

    return 0;
}