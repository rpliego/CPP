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
		throw std::runtime_error("Error: Open failed");
	
	if (!std::getline(file, line))
		throw std::invalid_argument("Error: data.csv its empty");
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

std::string trim(std::string str)
{
	std::size_t start;
	std::size_t end;

	start = str.find_first_not_of("\t\n\v\f\r ");
	if (start == std::string::npos)
		return "";
	end = str.find_last_not_of("\t\n\v\f\r ");

	// std::cout << start << std::endl;
	// std::cout << end - start + 1 << std::endl;
	str = str.substr(start, end - start + 1);

	return str;
}

std::string	validDate(std::string date)
{
	std::string aux[3];

	date = trim(date);

	if (date.length() > 10 || date.length() < 10)
		throw std::invalid_argument("Error: invalid date => " + date);

	aux[0] = date.substr(0, 4);
	aux[1] = date.substr(5, 2);
	aux[2] = date.substr(8, 2);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < (int)aux[i].length(); j++)
		{
			if (!isdigit(aux[i][j]))
				throw std::invalid_argument("Error: non digits found on date => " + date);
		}
	}
	if (std::atoi(aux[0].c_str()) > 2022 || std::atoi(aux[0].c_str()) < 2009 || std::atoi(aux[1].c_str()) > 12 || std::atoi(aux[2].c_str()) > 31)
		throw std::invalid_argument("Error: invalid date => " + date);
	else if (date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Error: invalid date => " + date);

	return date;
}

float	validValue(std::string strval)
{
	int flag = 0;
	strval = trim(strval);

	for (std::size_t i = 0; i < strval.length(); i++)
	{
		if (strval[i] == '.')
			flag++;
		if (!isdigit(strval[i]) && (flag > 1 || strval[i] != '.'))
			throw std::invalid_argument("Error: Invalid number => " + strval);
	}

	float out = std::atof(strval.c_str());

	if (out > 1000)
		throw std::invalid_argument("Error: number out of limits => " + strval);
	
	return out;
}

void	BitcoinExchange::_printOutput(std::string date, float value)
{
	std::map<std::string, float>::iterator it = _map.lower_bound(date);

	if (it != _map.begin())
	{
		if (it == _map.end() || it->first != date)
			--it;
	}

	std::cout << date << " => " << value << " = " << value * it->second << std::endl;
}

void	BitcoinExchange::_exchange(std::string line)
{
	std::string	date;
	std::string	strValue;
	int			split;
	float		value;

	split = line.find("|");
	if (split == (int)std::string::npos)
		throw std::invalid_argument("Error: '|' not found");

	// if (split = 0)
	// 	throw std::invalid_argument("Error: data not found");

	date = line.substr(0, split);
	if ((int)line.find_last_of("0123456789") < split)
		throw std::invalid_argument("Error: number not found");

	strValue = line.substr(split + 1);

	date = validDate(date);
	value = validValue(strValue);

	_printOutput(date, value);
}

void	BitcoinExchange::btcExchange(std::string av)
{	
	std::string		line;
	std::ifstream 	file(av.c_str());

	_initMap();
	
	if (!file.is_open())
		throw std::runtime_error("Error: Open failed");

	if(!std::getline(file, line))
		throw std::invalid_argument("Error: " + av + " its empty");
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

	file.close();
}