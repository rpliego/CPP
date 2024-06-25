#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default Constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Default Destructor called" << std::endl;
}

Ice::Ice(const Ice& toCopy)
{
	*this = toCopy;
}

Ice& Ice::operator=(const Ice& toCopy)
{
	this->_type = toCopy._type;

	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice();
}