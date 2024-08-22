#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <limits>
# include <exception>
# include <cstring>
# include <cstdlib>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <ctime>


class PmergeMe
{
	public:
		static void	 FordJohnson(char **arg);

	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& p);
		PmergeMe& operator=(const PmergeMe& p);
};

#endif