#include "Iter.hpp"
#include <iostream>

void	printc(char c)
{
	std::cout << c << std::endl;
}

int	main()
{
	char a[5] = "hola";

	iter(a, 5, printc);
}