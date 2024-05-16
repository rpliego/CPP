#include "Zombie.hpp"

Zombie::Zombie (void)
{
	this->_name = "default";
}

Zombie::Zombie (std::string name)
{
	this->_name = name;
}

Zombie::~Zombie (void)
{
	std::cout << "Destructo: " << this->_name  << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}