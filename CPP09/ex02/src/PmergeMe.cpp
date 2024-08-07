#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) {(void)p;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& p) {(void)p; return *this;}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


std::vector<int> generateJacobN(int size)
{
	std::vector<int> arrJbn;

	arrJbn.push_back(0);
	arrJbn.push_back(1);

	int i = 2;
	while (1)
	{
		int jn = arrJbn[i - 1] + 2 * arrJbn[i - 2];
		arrJbn.push_back(jn);
		++i;

		if (jn > size)
			break ;
	}

	for (int i = 0; i < (int)arrJbn.size(); i++)
	{
		std::cout << arrJbn[i] << std::endl;
	}
	
	return arrJbn;
}

void	splitPairVector(std::vector<int>& vec)
{
	std::vector<int> main;
}

void	PmergeMe::FordJohnson(std::vector<int> arr)
{
	std::vector<int> JacobNumbers = generateJacobN(arr.size());

	std::vector<int> vec;
	std::list<int> list;

	splitPairVector(vec);
}