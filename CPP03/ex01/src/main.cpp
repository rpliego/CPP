#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main()
{
	ScavTrap bob;

	std::cout << std::endl;
	//bob.nameSetter("bob");

	bob.attack("noseeee");
	std::cout << std::endl;

	std::cout << "nombre??: " << bob.nameGetter() << std::endl;
}