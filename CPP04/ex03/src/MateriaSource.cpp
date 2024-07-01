#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default Constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_slots[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Default Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& toCopy)
{
	std::cout << "MateriaSource Copy Constructor called" << std::endl;
	*this = toCopy;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& toCopy)
{
	for (int i = 0; i < 4; i++)
	{
		if (toCopy._slots[i])
			this->_slots[i] = toCopy._slots[i]->clone();
		else
			this->_slots[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource Inventory is full =(" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == this->_slots[i]->getType())
				return this->_slots[i]->clone();
	}
	return NULL;
}