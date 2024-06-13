#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {std::cout << "WrongAnimal Default Constructor called" << std::endl;}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal Destructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
    *this = toCopy;
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &toCopy)
{
    this->type = toCopy.type;
    return *this;
}


WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal Parametized Constructor called" << std::endl;
    this->type = type;
}


void    WrongAnimal::setType(const std::string newType) {this->type = newType;}

std::string WrongAnimal::getType() const {return this->type;}


void    WrongAnimal::makeSound() const {std::cout << "Some WrongAnimal sound" << std::endl;}