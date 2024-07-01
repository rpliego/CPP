#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {std::cout << "WrongAnimal Default Constructor called" << std::endl;}

WrongAnimal::~WrongAnimal() {std::cout << "WrongAnimal Destructor called" << std::endl;}

WrongAnimal::WrongAnimal(const WrongAnimal &toCopy)
{
    *this = toCopy;
    std::cout << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal  &WrongAnimal::operator=(const WrongAnimal &toCopy)
{
    this->_type = toCopy._type;
    return *this;
}


WrongAnimal::WrongAnimal(std::string _type)
{
    std::cout << "WrongAnimal Parametized Constructor called" << std::endl;
    this->_type = _type;
}


void    WrongAnimal::setType(const std::string new_Type) {this->_type = new_Type;}

std::string WrongAnimal::getType() const {return this->_type;}


void    WrongAnimal::makeSound() const {std::cout << "Some WrongAnimal sound" << std::endl;}