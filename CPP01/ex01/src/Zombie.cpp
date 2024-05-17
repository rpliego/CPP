#include "../inc/Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "default";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void){
	std::cout << "Destructor: " << this->_name  << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
