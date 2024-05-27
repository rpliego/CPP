#include "../inc/Fixed.hpp"

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

Fixed::Fixed(const int tofixed)
{
	this->_value = tofixed << _bits;
}

Fixed::Fixed(const float tofixed)
{
	this->_value = round(tofixed * (1 << _bits));
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}


float	Fixed::toFloat(void) const
{
	return round(this->_value / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return this->_value >> _bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
