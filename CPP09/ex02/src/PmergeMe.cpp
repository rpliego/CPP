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

	// for (int i = 0; i < (int)arrJbn.size(); i++)
	// {
	// 	std::cout << arrJbn[i] << std::endl;
	// }
	
	return arrJbn;
}

std::vector<std::pair<int, int> >	splitPairVector(std::vector<int>& vec, std::pair<bool, int>& odd)
{
	std::vector<std::pair<int, int> > pairs;

	if (vec.size() % 2 != 0)
	{
		odd.first = true;
		odd.second = vec.back();
		vec.pop_back();
	}

	for (std::size_t i = 0; i < vec.size(); i += 2)
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));

	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second); 
		// (pairs[i].first > pairs[i].second) ? std::swap(pairs[i].first, pairs[i].second) : void();
	}
	
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		for (std::size_t j = 0; j < pairs.size(); j++)
		{
			if (i != j && pairs[j].second > pairs[i].second)
			{
				std::cout << "i: " << i << " j: " << j << std::endl;
				std::swap(pairs[i], pairs[j]);
			}
		}
	}
	
	for (size_t i = 0; i < pairs.size(); ++i)
        std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;

	return pairs;
}

void	sortVector(std::vector<std::pair<int, int> > pairs, std::pair<bool, int> odd)
{
	(void)pairs;
	(void)odd;
	std::vector<int> mainv;
	std::vector<int> pend;

	//poner en main los numeros grandes de las parejas y en pend los pequenos;
}

void	PmergeMe::FordJohnson(std::vector<int> vec)
{
	std::vector<int> JacobNumbers = generateJacobN(vec.size());

	std::list<int> list;
	std::pair<bool, int> odd(false, 0);


	std::vector<std::pair<int, int> > pairs = splitPairVector(vec, odd);

	sortVector(pairs, odd);

}