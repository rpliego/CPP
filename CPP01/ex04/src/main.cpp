#include <fstream>
#include <iostream>
#include <cstdio>

void	check_errors(std::ifstream &in_file, std::ofstream &out_file, std::string s1)
{
	if (!in_file.is_open() || !out_file.is_open())
	{
		std::cout << "Error opening files" << std::endl;
		exit(1);
	}
	else if (s1.length() == 0)
	{
		std::cout << "s1 cant be empty" << std::endl;
		exit(1);
	}
}

void	replace(std::string file, std::string s1, std::string s2)
{
	std::ifstream in_file(file);
	std::ofstream out_file(file += ".replace");
	std::string	line;

	(void)s2;
	check_errors(in_file, out_file, s1);
	while (std::getline(in_file, line))
	{
		std::cout << line << std::endl;
		out_file << line << std::endl;
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	std::string file = av[1];
	std::string s1 = av[2];
	std::string	s2 = av[3];

	replace(file, s1, s2);

	return (0);
}