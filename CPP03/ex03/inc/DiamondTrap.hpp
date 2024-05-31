#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"


class DiamondTrap : public ScavTrap, public	FragTrap
{
	private:
		std::string	_name;

	public:
		DiamondTrap();
		~DiamondTrap();

		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &toCopy);

		DiamondTrap	&operator=(const DiamondTrap &toCopy);

		void	whoAmI();

};

#endif