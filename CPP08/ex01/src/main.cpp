#include "Span.hpp"

int main()
{
	Span span(10000);

	try
	{
		span.addMoreNumbers(1, 10000);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	span.printVector();
	std::cout << span.shortestSpan() << std::endl;
}