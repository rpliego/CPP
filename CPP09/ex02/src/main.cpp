#include "PmergeMe.hpp"

void parseInput(int ac, char **av)
{
	if (ac < 2){
		std::cout << "Invalid number of arguments" << std::endl;
		return ;
	}

	long n;
	for (int i = 1; i < ac; ++i)
	{
		for (std::size_t j = 0; j < strlen(av[i]); ++j) {
			if (!isdigit(av[i][j]))
				throw std::invalid_argument("Error: Invalid arguments"); 
		}
		
		n = std::strtol(av[i], NULL, 10);
		if (n < 0 || n > std::numeric_limits<int>::max())
			throw std::invalid_argument("Error: Invalid arguments");
	}
	
}

int main(int ac, char** av)
{
	try
	{
		parseInput(ac, av);
		PmergeMe::FordJohnson();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}