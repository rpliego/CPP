#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <iostream>
# include <stdexcept>
# include <fstream>
# include <string>
# include <cstdlib>
# include <limits>

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
		void	_printOutput(std::string date, float value);
};

#endif