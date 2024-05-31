#include "../inc/ScavTrap.hpp"

// Default Constructor
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_name = "default";
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}


// Default Destructor
ScavTrap::~ScavTrap() {std::cout << "ScavTrap Destructor called" << std::endl;}


// Adittional Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Adittional ScavTrap constructor called" << std::endl;
	this->_hitpoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}


// Copy Constructor
ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	*this = other;
}


// = Overload
ScavTrap	&ScavTrap::operator=(const ScavTrap &toCopy)
{
	this->_name = toCopy._name;
	this->_hitpoints = toCopy._hitpoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_attackDamage = toCopy._attackDamage;

	return *this;
}


// Status Functions
void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitpoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target 
			<< ", causing " << this->_attackDamage << " points of damage!!" << std::endl;
	}
	else if (this->_energyPoints < 0)
		std::cout << "ScavTrap " << this->_name << " cant attack without energipoints" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cant attack without hitpoints" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}