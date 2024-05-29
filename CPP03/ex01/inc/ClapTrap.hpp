 #ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define HITPOINTS 1
#define ENERGIPOINTS 2
#define ATTACKDAMAGE 3

class ClapTrap
{
	protected:
		std::string _name;
		int 		_hitpoints;
		int 		_energyPoints;
		int 		_attackDamage;

	public:
		ClapTrap();
		~ClapTrap();

		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);

		ClapTrap &operator=(const ClapTrap &toCopy);

		void			statsSetter(int	stat, int newValue);
		int				statsGetter(int	stat);
		void			nameSetter(std::string newName);
		std::string 	nameGetter();

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif