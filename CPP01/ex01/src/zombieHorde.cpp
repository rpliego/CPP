#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	Zombie *Horde;

	if (n < 0)
	{
		std::cout << "Invalid number" << std::endl;
		exit(1);
	}

	Horde = new Zombie[n];

	if (!name.empty()) {
		for (int i = 0; i < n; i++)
		Horde[i].setName(name);
	}

	return Horde;
}
