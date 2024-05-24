#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() 
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	this->_value = copy.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructoc called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
