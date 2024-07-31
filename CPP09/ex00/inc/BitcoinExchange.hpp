#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <string>
# include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void btcExchange(std::string av);

	private:
		std::map<std::string, float> _map;

		BitcoinExchange(const BitcoinExchange& toCopy);
		BitcoinExchange& operator=(const BitcoinExchange& toCopy);

		void	_initMap();
		void	_exchange(std::string line);
};

#endif