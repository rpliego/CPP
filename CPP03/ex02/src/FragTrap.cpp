#include "../inc/FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_name = "default";
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}


// Default Destructor
FragTrap::~FragTrap() {std::cout << "FragTrap Destructor called" << std::endl;}


// Copy Constructor
FragTrap::FragTrap(const FragTrap &toCopy)
{
	std::cout << "Copy FragTrap constructor called" << std::endl;
	*this = toCopy;
}


// Adittional Constructor
FragTrap::FragTrap(std::string name)
{
	std::cout << "Additional FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}


// = Overload
FragTrap	&FragTrap::operator=(const FragTrap &toCopy)
{
	this->_name = toCopy._name;
	this->_hitpoints = toCopy._hitpoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_attackDamage = toCopy._attackDamage;

	return *this;
}


// Status Functions
void	FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitpoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target 
			<< ", causing " << this->_attackDamage << " points of damage!!" << std::endl;
	}
	else if (this->_energyPoints < 0)
		std::cout << "FragTrap " << this->_name << " cant attack without energipoints" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " cant attack without hitpoints" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	std::cout << "This member function displays a positive high fives request on the standard output" << std::endl;
}
