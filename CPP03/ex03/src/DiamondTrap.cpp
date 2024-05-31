#include "../inc/DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "Default DiamondTrap constructor called" << std::endl;
	this->_name = "default";
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}

// Default Destructor
DiamondTrap::~DiamondTrap() {std::cout << "DiamondTrap Destructor called" << std::endl;}


// Adittional Constructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << "Adittional DiamondTrap constructor called" << std::endl;
	DiamondTrap::_name = name;
	ClapTrap::nameSetter(name + "_clap_name");
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 30;
}


// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap &toCopy)
{
	*this = toCopy;
}


// = Overload
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &toCopy)
{
	this->_name = toCopy._name;
	this->_hitpoints = toCopy._hitpoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_attackDamage = toCopy._attackDamage;

	return *this; 
}

// Especial Function
void	DiamondTrap::whoAmI()
{
	std::cout << "Name of DiamondTrap: " << this->_name << std::endl;
	std::cout << "Name of its ClapTrap: " << this->ClapTrap::_name << std::endl;
}