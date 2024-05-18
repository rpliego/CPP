#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon new_weapon)
{
	this->_name = name;
	this->_weapon = new_weapon;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}