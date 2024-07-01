#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal() : _type("Animal") {std::cout << "Animal Default Constructor called" << std::endl;}

Animal::~Animal() {std::cout << "Animal Destructor called" << std::endl;}

Animal::Animal(const Animal &toCopy)
{
    *this = toCopy;
    std::cout << "Animal Copy Constructor called" << std::endl;
}

Animal  &Animal::operator=(const Animal &toCopy)
{
    this->_type = toCopy._type;
    return *this;
}


Animal::Animal(std::string type)
{
    std::cout << "Animal Parametized Constructor called" << std::endl;
    this->_type = type;
}


void    Animal::setType(const std::string newType) {this->_type = newType;}

std::string Animal::getType() const {return this->_type;}


void    Animal::makeSound() const {std::cout << "Some animal sound" << std::endl;}
