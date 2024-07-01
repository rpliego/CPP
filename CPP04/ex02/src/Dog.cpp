#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog") 
{
    std::cout << "Dog Default Constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->_brain;   
}

Dog::Dog(const Dog &toCopy) : Animal(toCopy)
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    this->_brain = new Brain(*toCopy._brain);
}

Dog &Dog::operator=(const Dog &toCopy)
{
    std::cout << "Dog = overload called" << std::endl;
    if (this->_brain)
	    delete this->_brain;
    this->_type = toCopy._type;
    this->_brain = new Brain(*toCopy._brain);

    return *this;
}

void    Dog::makeSound() const{std::cout << "gUAU GuAu" << std::endl;}


void    Dog::setIdea(std::string idea) {this->_brain->setIdea(idea);}

void    Dog::printIdeas() {this->_brain->printIdeas();}

