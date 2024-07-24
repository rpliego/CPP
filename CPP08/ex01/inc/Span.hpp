#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <limits>
# include <algorithm>
# include <stdexcept>


class Span
{
	private:
		unsigned int _limit;
		unsigned int _size;
		std::vector<int> _vct;

	public:
		Span();
		~Span();
		Span(const Span& toCopy);
		Span& operator=(const Span& toCopy);

		Span(unsigned int limit);

		void	printVector() const;
		void	addMoreNumbers(int begin, int end);
		void	addNumber(int number);
		int		longestSpan();
		int		shortestSpan();
};

#endif