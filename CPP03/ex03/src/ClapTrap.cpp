#include "../inc/ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap() : _name("DefaultName"), _hitpoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}


// Additional Constructors
ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "Additional ClapTrap constructor called" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap() {std::cout << "ClapTrap Destructor called" << std::endl;}


// Copy Constructor
ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	*this = other;
}


// = overload
ClapTrap	&ClapTrap::operator=(const ClapTrap &toCopy)
{
	this->_attackDamage = toCopy._attackDamage;
	this->_energyPoints = toCopy._energyPoints;
	this->_hitpoints = toCopy._hitpoints;
	this->_name = toCopy._name;

	return *this;
}


// Setters
void	ClapTrap::statsSetter(int stat, int newValue)
{
	if (stat == HITPOINTS)
		this->_hitpoints = newValue;
	else if (stat == ENERGIPOINTS)
		this->_energyPoints = newValue;
	else if (stat == ATTACKDAMAGE)
		this->_attackDamage = newValue;
}

void	ClapTrap::nameSetter(std::string newName) {this->_name = newName;}


// Getters
int	ClapTrap::statsGetter(int stat)
{
	if (stat == HITPOINTS)
		return this->_hitpoints;
	else if (stat == ENERGIPOINTS)
		return this->_energyPoints;
	else if (stat == ATTACKDAMAGE)
		return this->_attackDamage;
	return -1;
}

std::string	ClapTrap::nameGetter() {return this->_name;}


// Action Functions
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitpoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target 
			<< ", causing " << this->_attackDamage << " points of damage!!" << std::endl;
	}
	else if (this->_energyPoints < 0)
		std::cout << "ClapTrap " << this->_name << " cant attack without energipoints" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cant attack without hitpoints" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints > 0)
	{
		this->_hitpoints -= amount;
		std::cout << "ClapTrap " << this->_name << " recived " << amount << " attack damage =(" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " is already dead, cannot receive more damage" << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitpoints > 0)
	{
		this->_energyPoints--;
		this->_hitpoints += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself by " << amount << "!!" << std::endl;
	}
	else if (this->_energyPoints < 0)
		std::cout << "ClapTrap " << this->_name << " cant repair itself without energipoints" << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cant repair itself without hitpoints" << std::endl;
}
