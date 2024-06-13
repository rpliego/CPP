#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iomanip>

int main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl << std::endl;

	std::cout << "Animal-> " << animal->getType() << " " << std::endl;
	std::cout << "Dog-> " << dog->getType() << " " << std::endl;
	std::cout << "Cat-> " << cat->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "AnimalSound-> ";
	animal->makeSound();
	std::cout << std::endl;
	std::cout << "DogSound-> ";
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "CatSound-> ";
	cat->makeSound();
	std::cout << std::endl;

	std::cout << std::endl << std::endl;
	
	
	std::cout << "AnimalDestructor-> ";
	delete animal;
	std::cout << std::endl;
	std::cout << "DogDestructor-> ";
	delete dog;
	std::cout << std::endl;
	std::cout << "CatDestructor-> ";
	delete cat;
	std::cout << std::endl;
	
	
	std::cout << std::endl << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongAnimalCat = new WrongCat();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << std::endl << std::endl;
	
	std::cout << "wrongAnimal -> " << wrongAnimal->getType() << " " << std::endl;
	std::cout << "wrongAnimalCat -> " << wrongAnimalCat->getType() << " " << std::endl;
	std::cout << "wrongCat -> " << wrongCat->getType() << " " << std::endl;

	std::cout << std::endl << std::endl;

	std::cout << "wrongAnimal -> ";
	wrongAnimal->makeSound();
	std::cout << "wrongAnimalCat -> ";
	wrongAnimalCat->makeSound();
	std::cout << "wrongCat -> ";
	wrongCat->makeSound();

	std::cout << std::endl << std::endl;

	delete wrongAnimal;
	delete wrongAnimalCat;
	delete wrongCat;

	return 0;
}