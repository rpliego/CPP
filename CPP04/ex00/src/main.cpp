#include "Animal.hpp"
#include "Dog.hpp"

int main()
{
    const Animal* animal = new Animal();
	const Animal* dog = new Dog();

	std::cout << std::endl << std::endl;

	std::cout << "Animal-> " << animal->getType() << " " << std::endl;
	std::cout << "Dog-> " << dog->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "AnimalSound-> ";
	animal->makeSound();
	std::cout << std::endl;
	std::cout << "DogSound-> ";
	dog->makeSound();
	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	
	
	std::cout << "AnimalDestructor-> ";
	delete animal;
	std::cout << std::endl;
	std::cout << "DogDestructor-> ";
	delete dog;
	std::cout << std::endl;
}