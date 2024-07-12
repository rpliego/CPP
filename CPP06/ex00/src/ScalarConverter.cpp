#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy) {(void)toCopy;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& toCopy) {(void)toCopy; return *this;}

void	ScalarConverter::convert(const std::string input)
{
	(void)input;
}