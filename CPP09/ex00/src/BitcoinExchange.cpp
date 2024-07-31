#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) {(void)toCopy;}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy) {(void)toCopy; return *this;}


//~~~~~~~Functions~~~~~~~//

void	BitcoinExchange::_initMap()
{
	std::ifstream 	file("data.csv");
	std::string 	line;
	std::string 	date;
	std::string 	strValue;
	float			value;

	if (!file.is_open())
		throw std::runtime_error("Error: while openning a file");
	
	std::getline(file, line);
	while (getline(file, line))
	{
		date = line.substr(0, line.find(","));
		strValue = line.substr(line.find(",") + 1);
		value = std::atof(strValue.c_str());
		_map[date] = value;
	}
	// for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); it++)
	// {
	// 	std::cout << it->first << " = " << it->second << std::endl;
	// }
	file.close();
}

void	BitcoinExchange::_exchange(std::string line)
{
	std::string	date;
	std::string	strValue;
	float		value;

	date = line.substr(0, line.find(","));
	strValue = line.substr(line.find(",") + 1);
	value = std::atof(strValue.c_str());
}

void	BitcoinExchange::btcExchange(std::string av)
{	
	std::string		line;
	std::ifstream 	file(av.c_str());

	_initMap();
	
	if (!file.is_open())
		throw std::runtime_error("Error: while openning a file");

	if(!std::getline(file, line))
		throw std::invalid_argument("File its empty");
	while (getline(file, line))
	{
		try
		{
			_exchange(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}