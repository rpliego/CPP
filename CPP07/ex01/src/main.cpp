#include "Iter.hpp"
#include <iostream>

void	printc(double c)
{
	std::cout << c << std::endl;
}

int	main()
{
	char	a[5] = "hola";
	float	b[5] = {43.23f, 4341.43f, 89.00001f, 1.22223225f, 0.1000343f};

	iter(a, 5, printc);
	iter(b, 5, printc);
}