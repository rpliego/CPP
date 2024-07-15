#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	Base::generate()
{
	int i = rand() % 3 + 1;

	std::cout << i << std::endl;
	if (i == 1)
	{
		std::cout << "Gen: Its A" << std::endl;
		return new A;
	}
	else if (i == 2)
	{
		std::cout << "Gen: Its B" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "Gen: Its C" << std::endl;
		return new C;
	}
}

void	Base::identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Detective: Its A" << std::endl;
	else if (b)
		std::cout << "Detective: Its B" << std::endl;
	else if (c)
		std::cout << "Detective: Its C" << std::endl;
}

void	Base::identify(Base& p)
{
	try
	{
		A a;

		a = dynamic_cast<A&>(p);
		std::cout << "Detective: Its A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		
	}

	try
	{
		B b;

		b = dynamic_cast<B&>(p);
		std::cout << "Detective: Its B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{

	}

	try
	{
		C c;

		c = dynamic_cast<C&>(c);
		std::cout << "Detective: Its C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		
	}
}