#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int	main()
{
	AMateria* ice = new Ice;
	ICharacter* bob = new Character("bob");
	ICharacter* elmanetas = new Character("enemy");

	bob->equip(ice);

	bob->use(0, *elmanetas);

	delete elmanetas;
	delete bob;
	//delete ice;
}