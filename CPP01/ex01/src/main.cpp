#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie *Horde;
	int	n = 2;

	Horde = zombieHorde(n, "");

	for (int i = 0; i < n; i++)
		Horde[i].announce();

	delete[] Horde;
}