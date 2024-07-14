#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy) {(void)toCopy;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& toCopy) {(void)toCopy; return *this;}

void	SpecialPseudos(bool aux, std::string input)
{
	if (aux)
	{
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;

		return ;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << std::endl;
        std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
	}
}

void	InputIsChar(char c)
{
	std::cout << "char: "<< c << std::endl;
	std::cout << "int: " << static_cast<int>(c) <<std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	InputIsInt(double i)
{
	if (i < 32 || i > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: "<< static_cast<char>(i) << std::endl;
	std::cout << "int: " << static_cast<int>(i) <<std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << i << std::endl;
}

void	InputIsFloat(double f)
{
	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: Overflow Error" <<std::endl;
	std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	std::cout << "double: " << f << std::endl;
}

void	InputIsDouble(double f)
{
	std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: Overflow Error" <<std::endl;
	std::cout << "float: Overflow Error" << std::endl;
	std::cout << "double: " << f << std::endl;
}

int	CheckNum(std::string input)
{
	for (unsigned long i = 0; i < input.length(); i++)
	{
		if (std::isalpha(input[i]) && input.at(i) != 'f' && input.at(i) != '.' && input.at(i) != 'e')
			return 1;
	}
	return 0;
}

void	ScalarConverter::convert(const std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return SpecialPseudos(0, input);
	else if (input == "-inf" || input == "+inf" || input == "nan")
		return SpecialPseudos(1, input);
	else if ((input.length() == 3 || input.length() == 4) && input.at(0) == '\'' && input[input.size() - 1] == '\'')
	{
		if (!std::isprint(input.at(1)) || input.length() != 3)
		{
			std::cout << "Non-printable ASCII character" << std::endl;
			return ;
		}
		return InputIsChar(input.at(1));	
	}
	if (CheckNum(input))
	{
		std::cout << "Input Error" << std::endl;
		return ;
	}

	double aux = strtod(input.c_str(), NULL);

	if (aux <= std::numeric_limits<int>::max() && aux >= std::numeric_limits<int>::min())
		return InputIsInt(aux);
	else if (aux <= std::numeric_limits<float>::max() && aux >= -std::numeric_limits<float>::max())
		return InputIsFloat(aux);
	else if (aux <= std::numeric_limits<double>::max() && aux >= -std::numeric_limits<double>::max())
		return InputIsDouble(aux);
	else
	{
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: Overflow Error" <<std::endl;
		std::cout << "float: Overflow Error" << std::endl;
		std::cout << "double: Overflow Erro" << std::endl;
	}
}