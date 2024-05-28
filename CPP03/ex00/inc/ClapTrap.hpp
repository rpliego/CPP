#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define HITPOINTS 1
#define ENERGIPOINTS 2
#define ATTACKDAMAGE 3

class ClapTrap
{
	private:
		std::string _name;
		int 		_hitpoints;
		int 		_energyPoints;
		int 		_attackDamage;

	public:
		ClapTrap(std::string name);
		~ClapTrap();

		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &toCopy);

		void	statsSetter(int	stat, int newValue);
		int		statsGetter(int	stat);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif