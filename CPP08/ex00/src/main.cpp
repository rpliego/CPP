#include "Easyfind.hpp"

int	main()
{
	std::srand(static_cast<unsigned int>(time(0)));
    std::vector<int> vec;

	for (int i = 0; i < 20; i++)
		vec.push_back(i);

	shuffle(vec);

	int i = rand() % 24 + 1;
	try
	{
		std::cout << i << std::endl;
		easyfind(vec, i);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}