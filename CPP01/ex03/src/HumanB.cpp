#include "HumanB.hpp"

HumanB::HumanB() {}

HumanB::HumanB(std::string name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " trys to atack, and realizes he dont have weapon... He starts to cry..." << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon)
{
	this->_weapon = &new_weapon;
}