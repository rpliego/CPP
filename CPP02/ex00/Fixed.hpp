#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_bits;
};

#endif