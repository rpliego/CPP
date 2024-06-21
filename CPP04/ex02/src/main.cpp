#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    Animal *b = new Dog;
    // Animal  a;

    // a.makeSound(); Compilation error!!!

    b->makeSound();

    return (0);
}