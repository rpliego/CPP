#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Default Constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Default Destructor called" << std::endl;
}

Cure::Cure(const Cure& toCopy)
{
	*this = toCopy;
}

Cure& Cure::operator=(const Cure& toCopy)
{
	this->_type = toCopy._type;

	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}