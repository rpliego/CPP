#include "Character.hpp"

Character::Character()
{
	std::cout << "Character Default Constructor called" << std::endl;
	_name = "default";
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	_floor = new AMateria*[1];
	_floor[0] = NULL;
}

Character::Character(std::string name)
{
	std::cout << "Character Parametized Constructor called" << std::endl;
	this->_name = name;
	_countFloor = 0;
	for (int i = 0; i < 4; i++)
		_slots[i] = NULL;
	_floor = new AMateria*[1];
	_floor[0] = NULL;
}

Character::Character(const Character& toCopy)
{
	std::cout << "Character Copy Constructor called" << std::endl;
	this->_name = toCopy._name;
	this->_countFloor = 0;
	this->_floor = new AMateria*[1];
	this->_floor[0] = NULL;

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

}

std::string const &	Character::getName() const {return this->_name;}