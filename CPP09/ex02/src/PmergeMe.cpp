#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& p) {(void)p;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& p) {(void)p; return *this;}


//~~~~~~~~~~~~~~~~~~~~Jacobsthal Numbers~~~~~~~~~~~~~~~~~~~~~~~~~//

std::vector<int> generateJacobN(int size)
{
	std::vector<int> arrJbn;
	arrJbn.push_back(1);
	arrJbn.push_back(3);
	int i = 2;
	while (1)
	{
		int jn = arrJbn[i - 1] + 2 * arrJbn[i - 2];
		if (jn > size)
			break ;
		arrJbn.push_back(jn);
		++i;
	}
	
	return arrJbn;
}


//~~~~~~~~~~~~~~~~~~~~Vector Algorithm~~~~~~~~~~~~~~~~~~~~~~~~~//

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
	}
	
	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		for (std::size_t j = 0; j < pairs.size(); j++)
		{
			if (i != j && pairs[j].second > pairs[i].second)
				std::swap(pairs[i], pairs[j]);
		}
	}

	return pairs;
}

std::vector<int>	mergeVector(std::vector<int> smain, std::vector<int> pend, std::pair<bool, int> odd)
{
	smain.insert(smain.begin(), pend[0]);
	pend.erase(pend.begin());

	size_t iterator = 0;
    size_t jacobindex = 3;
    std::vector<size_t> indexSequence;
	indexSequence.push_back(1);
    std::string last = "default";
	int item;

	std::vector<int> JacobNumbers = generateJacobN(pend.size() - 1);

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

	if (odd.first == true)
		smain.insert(std::lower_bound(smain.begin(), smain.end(), odd.second), odd.second);

	return smain;
}

std::vector<int>	sortVector(std::vector<std::pair<int, int> > pairs, std::pair<bool, int> odd)
{
	std::vector<int> smain;
	std::vector<int> pend;

	for (std::size_t i = 0; i < pairs.size(); i++)
	{
		smain.push_back(pairs[i].second);
		pend.push_back(pairs[i].first);
	}
	return (mergeVector(smain, pend, odd));
}


//~~~~~~~~~~~~~~~~~~~~List Algorithm~~~~~~~~~~~~~~~~~~~~~~~~~//

std::list<std::pair<int, int> > splitPairList(std::list<int> list, std::pair<bool, int>& odd)
{
	std::list<std::pair<int, int> > pairs;

	if (list.size() % 2 != 0)
	{
		odd.first = true;
		odd.second = list.back();
		list.pop_back();
	}

	for (std::list<int>::iterator i = list.begin(); i != list.end(); ++i)
	{
		std::list<int>::iterator next = i;
        ++next;
		pairs.push_back(std::make_pair(*i, *next));

		if (++i == list.end())
			break ;
	}


	std::list<std::pair<int, int> >::iterator it;
	std::list<std::pair<int, int> >::iterator it2;

	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	
	for (it = pairs.begin(); it != pairs.end(); it++)
	{
		for (it2 = pairs.begin(); it2 != pairs.end(); it2++)
		{
			if (it != it2 && it2->second > it->second)
			{
				std::swap(it->first, it2->first);
				std::swap(it->second, it2->second);
			}
		}
	}

	return pairs;
}

std::list<int> mergeList(std::list<int> smain, std::list<int> pend, std::pair<bool, int> odd)
{
	std::list<int>::iterator aux = pend.begin();
	smain.insert(smain.begin(), *aux);
	pend.erase(pend.begin());

	size_t iterator = 0;
    size_t jacobindex = 3;
    std::list<size_t> indexSequence;
	indexSequence.push_back(1);
    std::string last = "default";
	int item;

	std::vector<int> JacobNumbers = generateJacobN(pend.size() - 1);

	while (iterator < pend.size())
	{
		std::list<int>::iterator pendit = pend.begin();
        if (!JacobNumbers.empty() && last != "jacob")
		{
            indexSequence.push_back(JacobNumbers[0]);
            size_t insert_index = JacobNumbers[0] - 1;
			std::advance(pendit, insert_index);
            item = *pendit;
            JacobNumbers.erase(JacobNumbers.begin());
            last = "jacob";
		}
		else
		{
            if (std::find(indexSequence.begin(), indexSequence.end(), iterator + 1) != indexSequence.end())
                iterator++;
			
			std::list<int>::iterator aux2 = pend.begin();
			std::advance(aux2, iterator);
            item = *aux2;
            indexSequence.push_back(iterator + 1);
            last = "not-jacob";
		}

		std::list<int>::iterator insertion_point = std::lower_bound(smain.begin(), smain.end(), item);
        smain.insert(insertion_point, item);

        iterator++;
        jacobindex++;
	}

	if (odd.first == true)
		smain.insert(std::lower_bound(smain.begin(), smain.end(), odd.second), odd.second);

	return smain;
}

std::list<int> sortList(std::list<std::pair<int, int> > pairs, std::pair<bool, int> odd)
{
	std::list<int> smain;
	std::list<int> pend;

	std::list<std::pair<int, int> >::iterator it;

	for (it = pairs.begin(); it != pairs.end(); *it++)
	{
		smain.push_back(it->second);
		pend.push_back(it->first);
	}
	return mergeList(smain, pend, odd);
}

std::list<int> createList(char **arg)
{
	std::list<int> out;

	for (size_t i = 0; arg[i]; i++)
		out.push_back(std::atof(arg[i]));

	return out;
}

std::vector<int> createVector(char **arg)
{
	std::vector<int> out;

	for (size_t i = 0; arg[i] != NULL; i++)
		out.push_back(std::atof(arg[i]));

	return out;
}

//~~~~~~~~~~~~~~~~~~~~Main Function~~~~~~~~~~~~~~~~~~~~~~~~~//

void	PmergeMe::FordJohnson(char **arg)
{
	std::vector<int> vec = createVector(arg);
	std::pair<bool, int> odd(false, 0);


	std::cout << std::endl << "\x1b[33;1mUnsorted Vector: \x1b[0m";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	clock_t t;
	t = clock();

	if (vec.size() > 1)
	{
		std::vector<std::pair<int, int> > pairsv = splitPairVector(vec, odd);
		vec = sortVector(pairsv, odd);
	}
	t = clock() - t;

	std::cout << "\x1b[33;1mVector after sort: \x1b[0m";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\x1b[34;4mTime to process a range of "<< vec.size() <<" elements with std::vector -> \x1b[0m" << static_cast<double>(t) / CLOCKS_PER_SEC << std::endl << std::endl;
	


	std::list<int> list = createList(arg);
	odd.first = false;
	odd.second = 0;

	std::cout << "\x1b[32;1mUnsorted List: \x1b[0m";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	t = clock();

	if (list.size() > 1)
	{
		std::list<std::pair<int, int> > pairsl = splitPairList(list, odd);
		list = sortList(pairsl, odd);
	}
	
	t = clock() - t;

	std::cout << "\x1b[32;1mList after sort: \x1b[0m";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\x1b[34;4mTime to process a range of "<< list.size() <<" elements with std::list -> \x1b[0m" << static_cast<double>(t) / CLOCKS_PER_SEC<< std::endl << std::endl;
}