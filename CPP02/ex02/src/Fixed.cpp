#include "../inc/Fixed.hpp"

const int Fixed::_bits = 8;

//~~Default constructor and destructor~~//
Fixed::Fixed() 
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructoc called" << std::endl;
}


//~~~~~~~~Copy constructor~~~~~~~~~//
Fixed::Fixed(const Fixed &copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	_value = copy.getRawBits();
}


//~~~~Addiotional constructors~~~~//
Fixed::Fixed(const int tofixed)
{
	this->_value = tofixed << _bits;
}

Fixed::Fixed(const float tofixed)
{
	this->_value = round(tofixed * (1 << _bits));
}


//~~~~~~~~~~~Overloads~~~~~~~~~~~//
Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = copy.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return this->_value > copy._value;
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return this->_value < copy._value;
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return this->_value >= copy._value;
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return this->_value <= copy._value;
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return this->_value == copy._value;
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return this->_value != copy._value;
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed result = (this->toFloat() + other.toFloat());

	return (result);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed result = (this->toFloat() - other.toFloat());

	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed result (this->toFloat() * other.toFloat());

	return result;
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed result (this->toFloat() / other.toFloat());

	return result;
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed result (*this);

	++this->_value;
	return result;
}

Fixed	&Fixed::operator--()
{
	this->_value--;

	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed aux(*this);

	--this->_value;
	return (aux);
}

//~~~~~Public functions~~~~~//
int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return(static_cast<float>(this->_value) / (1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (static_cast<int>(this->_value >> _bits));
}

const Fixed	&Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f2 < f1)
		return f2;
	return (f1);
}

const Fixed	&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f2 < f1)
		return f2;
	return (f1);
}

const Fixed	&Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f2 > f1)
		return f2;
	return (f1);
}

const Fixed	&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f2 > f1)
		return f2;
	return (f1);
}