#include <iostream>

int	main(void)
{
	std::string s1 = "HI THIS IS BRAIN";
	std::string	*s2 = &s1;
	std::string	s3 = s1;

	std::cout << &s1 << std::endl;
	std::cout << &s2 << std::endl;
	std::cout << &s3 << std::endl << std::endl;

	std::cout << s1 << std::endl;
	std::cout << *s2 << std::endl;
	std::cout << s3 << std::endl;
}