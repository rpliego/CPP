#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal() 
{
    std::cout << "Dog Default Constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->brain;   
}

Dog::Dog(const Dog &toCopy) : Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = toCopy;
}

Dog &Dog::operator=(const Dog &toCopy)
{
    this->type = toCopy.type;
    this->brain = new Brain(*toCopy.brain);

    return *this;
}

void    Dog::makeSound() const{std::cout << "gUAU GuAu" << std::endl;}


void    Dog::setIdea(std::string idea) {this->brain->setIdea(idea);}

void    Dog::printIdeas() {this->brain->printIdeas();}

