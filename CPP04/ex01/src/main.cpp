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
   
    cat.printIdeas();
    
   

    return (0);
}