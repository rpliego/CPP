#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->brain;
}

Cat::Cat(const Cat &toCopy) : Animal()
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = toCopy;
}

Cat &Cat::operator=(const Cat &toCopy)
{
    this->type = toCopy.type;
    this->brain = new Brain(*toCopy.brain);

    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Miauuuuuuu" << std::endl;
}


void    Cat::setIdea(std::string idea) {this->brain->setIdea(idea);}

void    Cat::printIdeas() {this->brain->printIdeas();}