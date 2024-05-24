#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const int tofixed);
		Fixed(const float tofixed);

		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif