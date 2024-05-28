#include "../inc/ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap("Default")
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_name = "default";
}


// Default Destructor
ScavTrap::~ScavTrap() {std::cout << "ScavTrap Destructor called" << std::endl;}


// // Copy Constructor
// ScavTrap::ScavTrap(const ScavTrap &other)
// {
// 	std::cout << "Default ScavTrap constructor called" << std::endl;
// 	*this = other;
// }


// // = Overload
// ScavTrap	&ScavTrap::operator=(const ScavTrap &toCopy)
// {
	
// }