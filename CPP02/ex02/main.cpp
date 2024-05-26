#include "Fixed.hpp"

int main( void )
{
	Fixed a(4.f);
	Fixed b(3.9999999f);
	
	Fixed test(0);
	Fixed aux(1);

	//std::cout << (a / b) << test << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}