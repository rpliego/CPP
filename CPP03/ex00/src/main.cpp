#include "../inc/ClapTrap.hpp"

int	main()
{
	std::cout << "--------------------------------------" << std::endl;
	ClapTrap bob("Bob");
	ClapTrap paco;
	ClapTrap aux(paco);

	paco.nameSetter("Paco");
	std::cout << "--------------------------------------" << std::endl;
	bob.statsSetter(ATTACKDAMAGE, 1);
	bob.statsSetter(ENERGIPOINTS, 4);
	paco.statsSetter(HITPOINTS, 2);

	bob.attack("Paco");
	paco.takeDamage(1);
	std::cout << "--------------------------------------" << std::endl;
	paco.beRepaired(1);
	std::cout << "--------------------------------------" << std::endl;
	bob.attack("Paco");
	paco.takeDamage(1);
	std::cout << "--------------------------------------" << std::endl;
	bob.attack("Paco");
	paco.takeDamage(1);
	std::cout << "--------------------------------------" << std::endl;
	bob.attack("Paco");
	paco.takeDamage(1);
	std::cout << "--------------------------------------" << std::endl;
	paco.beRepaired(1);
	std::cout << "--------------------------------------" << std::endl;
	bob.attack("someone");
	bob.beRepaired(3);
	std::cout << "--------------------------------------" << std::endl;
	aux.beRepaired(100);
	std::cout << "--------------------------------------" << std::endl;
}