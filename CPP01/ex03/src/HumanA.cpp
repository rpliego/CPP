#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &new_weapon) : _weapon(new_weapon)
{
	this->_name = name;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}