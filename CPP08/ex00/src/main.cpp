#include "Easyfind.hpp"

int	main()
{
	int n = 6;
	std::array<int, 6> ar = {1, 2, 3, 4, 5, 6};

	try
	{
		easyfind(ar, n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}