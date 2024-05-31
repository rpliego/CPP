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
FragTrap::FragTrap(std::string name) : ClapTrap(name)
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
void	FragTrap::highFiveGuys()
{
	std::cout << "This member function displays a positive high fives request on the standard output" << std::endl;
}
