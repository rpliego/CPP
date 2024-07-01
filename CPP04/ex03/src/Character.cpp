#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor called" << std::endl;
	_name = "default";
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	_floor = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Character Parametized Constructor called" << std::endl;
	this->_name = name;
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	_floor = NULL;
}

Character::Character(const Character& toCopy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	this->_name = toCopy._name;
	this->_countFloor = 0;
	_floor = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (toCopy._slots[i] == NULL)
			this->_slots[i] = NULL;
		else
			this->_slots[i] = toCopy._slots[i]->clone();
	}
}

Character::~Character()
{
	std::cout << "Character Default Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i])
			delete _slots[i];
	}
	
	for (int i = 0; i < this->_countFloor; i++)
	{
		if (this->_floor[i] != NULL)
			delete this->_floor[i];
	}
	delete[] this->_floor;
}

Character& Character::operator=(const Character& toCopy)
{
	std::cout << "Character = overload called" << std::endl;
	this->_name = toCopy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] != NULL)
		{
			delete this->_slots[i];
			this->_slots[i] = NULL;
		}
		if (toCopy._slots[i] != NULL)
			this->_slots[i] = toCopy._slots[i]->clone();
		else
			this->_slots[i] = NULL;
	}
	return *this;
}

std::string const &	Character::getName() const {return this->_name;}

void	Character::equip(AMateria* m)
{
	std::cout << "Character equip function called" << std::endl;
	int	i = -1;

	while (++i < 4)
	{
		if (this->_slots[i] == m)
		{
			std::cout << "Cant equip the same materia" << std::endl;
			return ;
		}
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m->clone();
			return ;
		}
	}
	std::cout << "Character Inventory is full =(" << std::endl;
}

void	Character::unequip(int indx)
{
	std::cout << "Character Unequip function called" << std::endl;
	if (indx < 4 && indx > -1 && this->_slots[indx] != NULL)
	{
		this->_countFloor++;
		AMateria** newTrash = new AMateria* [this->_countFloor];
		for (int i = 0; i < this->_countFloor -1; i++)
			newTrash[i] = this->_floor[i];
		newTrash[_countFloor - 1] = this->_slots[indx];
		delete[] this->_floor;
		this->_floor = newTrash;
		this->_slots[indx] = NULL;
	}
}

void	Character::use(int	indx, ICharacter& target)
{
	if (indx > -1 && indx < 4 && this->_slots[indx])
	{
		this->_slots[indx]->use(target);
	}
}