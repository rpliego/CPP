#include "RPN.hpp"

void	checkInput(int ac, char** av)
{
	if (ac != 2)
		throw std::invalid_argument("Error: Only one argument is required");
	
	std::istringstream iss(av[1]);
	std::string token;

	while (iss >> token)
	{
		if (token.length() != 1 || (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '/' && token[0] != '*'))
			throw std::invalid_argument("Error: no");
	}
	
}

int	main(int ac, char **av)
{
	try
	{
		checkInput(ac, av);
		RPN::RPNcalculator(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}