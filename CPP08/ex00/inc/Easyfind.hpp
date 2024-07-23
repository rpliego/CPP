#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <array>
# include <exception>

template <typename T>
void	easyfind(T c, int f)
{
	for (int i = 0; i < (int)c.size(); i++)
	{
		if (c.at(i) == f)
		{
			std::cout << "The first ocurrence is at index: " << i << std::endl;
			return ;
		}
	}
	throw std::logic_error("Int not found");
}


#endif