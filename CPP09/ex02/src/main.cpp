#include "PmergeMe.hpp"

std::vector<int> parseInput(int ac, char **av)
{
	if (ac < 2)
		throw std::invalid_argument("Error: Invalid number of arguments");

	std::vector<int> out;
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
		out.push_back(n);
	}
	return out;
}

int main(int ac, char** av)
{
	std::vector<int> arr;
	try
	{
		arr = parseInput(ac, av);
		PmergeMe::FordJohnson(arr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}