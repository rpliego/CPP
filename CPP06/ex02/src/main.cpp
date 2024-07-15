#include "Base.hpp"

int	main()
{
	Base detec;
	Base* sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(*sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	sus = detec.generate();
	detec.identify(sus);
	delete sus;
	std::cout << "--------------------" << std::endl;

	return 0;
}