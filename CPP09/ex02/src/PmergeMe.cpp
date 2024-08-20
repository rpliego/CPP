#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) {(void)p;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& p) {(void)p; return *this;}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


std::vector<int> generateJacobN(int size)
{
	std::vector<int> arrJbn;

	arrJbn.push_back(1);
	arrJbn.push_back(3);

	for (int i = 2; i < size; i++)
		arrJbn.push_back(arrJbn[i - 1] + 2 * arrJbn[i - 2]);

	std::cout << "Jacobsthal: ";
	for (size_t i = 0; i < arrJbn.size(); i++)
	{
		std::cout << arrJbn[i]<< " ";
	}
	std::cout << std::endl;
	
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
				std::swap(pairs[i], pairs[j]);
		}
	}
	
	// for (size_t i = 0; i < pairs.size(); ++i)
    //     std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ")" << std::endl;

	return pairs;
}

std::vector<int>	mergeVector(std::vector<int> smain, std::vector<int> pend)
{
	smain.insert(smain.begin(), pend[0]);
	pend.erase(pend.begin());


	std::cout << "main: ";
	for (size_t i = 0; i < smain.size(); i++)
	{
		std::cout << " " << smain[i]; 
	}
	std::cout << std::endl;

	std::cout << "pend: ";
	for (size_t i = 0; i < pend.size(); i++)
	{
		std::cout << " " << pend[i]; 
	}
	std::cout << std::endl;
	

	size_t iterator = 0;
    size_t jacobindex = 3;
    std::vector<size_t> indexSequence;
	indexSequence.push_back(1);
    std::string last = "default";
	int item;

	std::vector<int> JacobNumbers = generateJacobN(pend.size());


	while (iterator < pend.size())
	{
        if (!JacobNumbers.empty() && last != "jacob")
		{
            indexSequence.push_back(JacobNumbers[0]);
            size_t insert_index = JacobNumbers[0] - 1;
            item = pend[insert_index];
            JacobNumbers.erase(JacobNumbers.begin());
            last = "jacob";
		}
		else
		{
            if (std::find(indexSequence.begin(), indexSequence.end(), iterator + 1) != indexSequence.end())
                iterator++;
			
            item = pend[iterator];
            indexSequence.push_back(iterator + 1);
            last = "not-jacob";
		}
	
		std::vector<int>::iterator insertion_point = std::lower_bound(smain.begin(), smain.end(), item);
        smain.insert(insertion_point, item);
        
        iterator++;
        jacobindex++;
	}

	return smain;
}

std::vector<int>	sortVector(std::vector<std::pair<int, int> > pairs)
{
	std::vector<int> smain;
	std::vector<int> pend;

	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		smain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	
	// std::cout << "main: ";
	// for (size_t i = 0; i < smain.size(); i++)
	// {
	// 	std::cout << " " << smain[i]; 
	// }
	// std::cout << std::endl;

	// std::cout << "pend: ";
	// for (size_t i = 0; i < pend.size(); i++)
	// {
	// 	std::cout << " " << pend[i]; 
	// }
	// std::cout << std::endl;

	return (mergeVector(smain, pend));
}

void	PmergeMe::FordJohnson(std::vector<int> vec)
{

	std::list<int> list;
	std::pair<bool, int> odd(false, 0);


	std::vector<std::pair<int, int> > pairs = splitPairVector(vec, odd);

	vec = sortVector(pairs);

	std::cout << "Sorted: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}