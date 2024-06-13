#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat Default Constructor called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat() {std::cout << "Cat Destructor called" << std::endl;}

Cat::Cat(const Cat &toCopy) : Animal()
{
    std::cout << "Cat Copy Constructor called" << std::endl;
    *this = toCopy;
}

Cat &Cat::operator=(const Cat &toCopy)
{
    this->type = toCopy.type;

    return *this;
}

void    Cat::makeSound() const
{
    std::cout << "Miauuuuuuu" << std::endl;
}