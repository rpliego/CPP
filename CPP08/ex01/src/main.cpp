#include "Span.hpp"

int main()
{
	Span span(10);

	try
	{
		span.addMoreNumbers(1, 100);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	span.printVector();
	std::cout << span.shortestSpan() << std::endl;
}