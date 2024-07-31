#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc;

	try
	{
		if (ac != 2)
			throw std::invalid_argument("Invalid arguments");
		btc.btcExchange(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}