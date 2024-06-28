#include "AMateria.hpp"

AMateria::AMateria() : _type("AMateria")
{
    std::cout << "AMateria Default Constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Default Destructor called" << std::endl;
}

AMateria::AMateria(const AMateria& toCopy)
{
	std::cout << "AMateria Copy Constructor called" << std::endl;
	*this = toCopy;
}

AMateria&	AMateria::operator=(const AMateria& toCopy)
{
	std::cout << "AMateria = overload called" << std::endl;
	this->_type = toCopy._type;

	return *this;
}

AMateria::AMateria(const std::string& type)
{
	std::cout << "AMateria Parametized Constructor called" << std::endl;
	this->_type = type;
}

const std::string&	AMateria::getType() const {return this->_type;}
