#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat Default Constructor called" << std::endl;
    this->_type = "WrongCat";
}

WrongCat::~WrongCat() {std::cout << "WrongCat Destructor called" << std::endl;}

WrongCat::WrongCat(const WrongCat &toCopy) : WrongAnimal()
{
    std::cout << "WrongCat Copy Constructor called" << std::endl;
    *this = toCopy;
}

WrongCat &WrongCat::operator=(const WrongCat &toCopy)
{
    this->_type = toCopy._type;

    return *this;
}

void    WrongCat::makeSound() const
{
    std::cout << "uuuuuuuaiM" << std::endl;
}