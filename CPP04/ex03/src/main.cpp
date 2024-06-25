#include "AMateria.hpp"
#include "Ice.hpp"

int	main()
{
	AMateria* bob;

	bob = new Ice;

	std::cout << bob->getType() << std::endl;



	delete bob;
}