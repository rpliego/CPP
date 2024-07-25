#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	MutantStack<int> a;

	MutantStack<int>::iterator it = mstack.begin();

	mstack.push(4);

	std::cout << mstack.top() << std::endl;

	a = mstack;

	std::cout << a.top() << std::endl;
}
