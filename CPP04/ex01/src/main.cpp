#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--- CREATING A CAT: ---" << std::endl;
    Cat cat = Cat();
    cat.makeSound();
    cat.printIdeas();
    cat.setIdea("im a cat");
    std::cout << "--- ADDED 1 IDEA: ---" << std::endl;
    cat.printIdeas();
    for (int i = 0; i < 110; i ++)
        cat.setIdea("a");
    std::cout << "--- ADDED 110 IDEAS: ---" << std::endl;
    cat.printIdeas();
    for (int i = 0; i < 10; i ++)
        cat.setIdea("b");
    std::cout << "--- ADDED 10 IDEAS: ---" << std::endl;
    cat.printIdeas();
    
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--- CHECKING IF THE BRAIN IS DELETED BEFORE REASSIGNMENT AND NO LEAKS: ---" << std::endl;
    Dog* dd2 = new Dog();
    dd2->setIdea("lalala");
    Dog* dd3 = new Dog();
    *dd2 = *dd3;
    delete dd2;
    delete dd3;

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--- CHECKING THAT COPIES ARE DEEP: ---" << std::endl;
    Dog dog = Dog();
    dog.setIdea("im a dog");
    std::cout << "--- ideas of dog:" << std::endl;
    dog.printIdeas();
    Dog dogcopy = Dog(dog);
    std::cout << "--- ideas of copy dog:" << std::endl;
    dogcopy.printIdeas();
    dogcopy.setIdea("im a copy");
    std::cout << "--- ideas of copy dog:" << std::endl;
    dogcopy.printIdeas();
    std::cout << "--- ideas of dog:" << std::endl;
    dog.printIdeas();

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--- CHECKING THAT POINTER COPIES ARE DEEP: ---" << std::endl;
    Dog* dogp = new Dog();
    dogp->setIdea("im a dog");
    std::cout << "--- ideas of dog:" << std::endl;
    dogp->printIdeas();
    Dog* dogcopyp = new Dog(*dogp);
    std::cout << "--- ideas of copy dog:" << std::endl;
    dogcopyp->printIdeas();
    dogcopyp->setIdea("im a copy");
    std::cout << "--- ideas of copy dog:" << std::endl;
    dogcopyp->printIdeas();
    std::cout << "--- ideas of dog:" << std::endl;
    dogp->printIdeas();

    delete dogp;
    delete dogcopyp;

    std::cout << "--------------------------------------" << std::endl;
    std::cout << "--- SUBJECT EXPAMLE THAT SHOULD NOT CREATE A LEAK: ---" << std::endl;
    const Animal* acat = new Cat();

    delete acat;

    std::cout << "--------------------------------------" << std::endl;

    std::cout << "--- CREATING ARRAY OF DIFFERENT ANIMALS: ---" << std::endl;
    Cat *c1 = new Cat();
    Cat *c2 = new Cat();
    Animal *c3 = new Cat();
    Dog *d1 = new Dog();
    Dog *d2 = new Dog();
    Animal *d3 = new Dog();

    Animal *a[] = {c1, c2, c3, d1, d2, d3};
    std::cout << "--- SOUNDS OF EACH ANIMAL IN THE ARRAY AND DELETING: ---" << std::endl;
    for (int i = 0; i < 6; i ++)
    {
        a[i]->makeSound();
        delete a[i];
    }

    std::cout << "--------------------------------------" << std::endl;

    return (0);
}