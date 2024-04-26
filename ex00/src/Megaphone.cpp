#include <iostream>

int main(int ac, char **av)
{
	int	i = 0;

    if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (av[++i])
	{
		if (i > 1)
			std::cout << " ";
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
    return 0;
}
