#include "Zombie.hpp"

int	main(void)
{
	Zombie user;
	Zombie bob("bob");
	Zombie *tomas;

	bob.announce();
	user.announce();
	tomas = newZombie("Tomas");
	tomas->announce();
	ramdomChump("joselin");

	delete tomas;
	return 0;
}