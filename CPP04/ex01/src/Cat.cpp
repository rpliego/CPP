#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    this->type = "Cat";
    this->_brain = new Brain;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->_brain;
}

Cat::Cat(const Cat &toCopy) : Animal()
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = toCopy;
}

Cat &Cat::operator=(const Cat &toCopy)
{
    delete this->_brain;
    this->type = toCopy.type;
    this->_brain = new Brain(*toCopy._brain);

    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Miauuuuuuu" << std::endl;
}


void    Cat::setIdea(std::string idea) {this->_brain->setIdea(idea);}

void    Cat::printIdeas() {this->_brain->printIdeas();}