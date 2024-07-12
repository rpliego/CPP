#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>


int main(int ac, char** av)
{
	(void)ac;
    if (ac != 2)
	{
		std::cout << "Only one argument required" << std::endl;
		return 0;
	}

	double a = strtod(av[1], NULL);
	std::cout << a << std::endl;
	//ScalarConverter::convert(av[1]);
	
    return 0;
}