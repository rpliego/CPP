#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "./ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		~FragTrap();

		FragTrap(std::string name);
		FragTrap(const FragTrap &toCopy);

		FragTrap &operator=(const FragTrap &toCopy);

		//void	attack(const std::string &target);
		void	highFiveGuys();
};

#endif