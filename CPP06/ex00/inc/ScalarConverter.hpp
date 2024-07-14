#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& toCopy);
		ScalarConverter& operator=(const ScalarConverter& toCopy);

	public:
		static	void	convert(const std::string input);
};

#endif