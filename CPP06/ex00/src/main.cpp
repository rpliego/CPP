#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>


int main(int ac, char** av)
{
    if (ac != 2)
	{
		std::cout << "Only one argument required" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
	
	// (void)ac;
	// (void)av;

	// ScalarConverter::convert("-inf");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("+inf");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("nan");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("-inff");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("+inff");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("nanf");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("-2.00009");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("4456.500000");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("234567");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("64");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("2147483649678.00000001");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("'b'");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("-9876534567898823456789876543456789876534567890987654345678909.0f");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("4456.000000");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("-8");
	// std::cout << "-------------------------------" << std::endl;
	// ScalarConverter::convert("64a");
	// std::cout << "-------------------------------" << std::endl;

    return 0;
}