#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon club("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("PORQQQEEEE");
	bob.attack();
}