#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "./ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();

		ScavTrap(std::string name);
		// ScavTrap(const ScavTrap &other);

		// ScavTrap &operator=(const ScavTrap &toCopy);
};

#endif