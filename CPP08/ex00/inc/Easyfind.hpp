#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <algorithm> 
# include <exception>

template <typename T>
void	easyfind(T c, int f)
{
	for (int i = 0; i < (int)c.size(); i++)
	{
		if (c[i] == f)
		{
			std::cout << "The first ocurrence is at index: " << i << std::endl;
			return ;
		}
	}
	throw std::logic_error("Int not found");
}


template <typename T>
void shuffle(std::vector<T>& vec)
{
    for (std::size_t i = vec.size() - 1; i > 0; --i)
	{
        std::size_t j = rand() % (i + 1);
        std::swap(vec[i], vec[j]);
    }
}

#endif