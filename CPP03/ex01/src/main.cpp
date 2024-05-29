#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main()
{
	ScavTrap bob("Boby");

	std::cout << std::endl;
	//bob.nameSetter("bob");

	bob.attack("noseeee");
	bob.takeDamage(1000);
	bob.takeDamage(1000);
	bob.beRepaired(1000);

	bob.guardGate();
	std::cout << std::endl;

}