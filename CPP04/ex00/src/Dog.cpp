#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog Default Constructor called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog() {std::cout << "Dog Destructor called" << std::endl;}

Dog::Dog(const Dog &toCopy) : Animal()
{
    std::cout << "Dog Copy Constructor called" << std::endl;
    *this = toCopy;
}

Dog &Dog::operator=(const Dog &toCopy)
{
    this->type = toCopy.type;

    return *this;
}

void    Dog::makeSound() const
{
    std::cout << "gUAU GuAu" << std::endl;
}