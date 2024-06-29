#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor called" << std::endl;
	_name = "default";
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	//_floor = new AMateria*[1];
	_floor = NULL;
	//_floor[0] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Character Parametized Constructor called" << std::endl;
	this->_name = name;
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	//_floor = new AMateria*[1];
	_floor = NULL;
	//_floor[0] = NULL;
}

Character::Character(const Character& toCopy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	this->_name = toCopy._name;
	this->_countFloor = 0;
	//this->_floor = new AMateria*[1];
	_floor = NULL;
	//_floor[0] = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (toCopy._slots[i] == NULL)
			this->_floor[i] = NULL;
		else
			this->_floor[i] = toCopy._slots[i]->clone();
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
	//delete[] this->_slots;
	
	for (int i = 0; i < this->_countFloor; i++)
	{
		delete this->_floor[i];
	}
	delete[] this->_floor;
}

std::string const &	Character::getName() const {return this->_name;}

void	Character::equip(AMateria* m)
{
	int	i = -1;

	while (++i < 4)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			return ;
		}
	}
	std::cout << "Inventori is full =(" << std::endl;
}

void	Character::unequip(int indx)
{
	if (indx < 4 && indx > -1 && this->_slots[indx])
	{
		this->_countFloor++;
		AMateria** newTrash = new AMateria* [this->_countFloor];
		for (int i = 0; i < this->_countFloor; i++)
		{
			newTrash[i] = this->_floor[i];
		}
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