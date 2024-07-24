#include "Span.hpp"

Span::Span() : _limit(0), _size(0) {}

Span::~Span() {}

Span::Span(const Span& toCopy) {*this = toCopy;}

Span&	Span::operator=(const Span& toCopy)
{
	this->_size = toCopy._size;
	this->_vct = toCopy._vct;

	return *this;
}

Span::Span(unsigned int limit) : _limit(limit), _size(0) {}

void	Span::printVector() const
{
	for (size_t i = 0; i < _size && i < _limit; i++)
		std::cout << _vct[i] << std::endl;
}

void	Span::addNumber(int number)
{
	if (_size + 1 > _limit)
		throw std::logic_error("Span is full");
	_size++;
	_vct.push_back(number);
}

void	Span::addMoreNumbers(int begin, int end)
{
	for (int i = begin; i <= end; i++)
		this->addNumber(i);
	
}

int		Span::longestSpan()
{
	if (_vct.size() <= 1)
		throw std::logic_error("Span needs at least 2 numbers to find the longest span");

	std::sort(_vct.begin(), _vct.end());

	return _vct.back() - _vct.front();
}

int		Span::shortestSpan()
{
	int ret = std::numeric_limits<int>::max();
	int span;

	if (_vct.size() <= 1)
		throw std::logic_error("Span needs at least 2 numbers to find the shortest span");

	std::sort(_vct.begin(), _vct.end());

	for (size_t i = 1; i < _vct.size(); i++)
	{
		span = _vct[i] - _vct[i - 1];
		if (span < ret)
			ret = span;
	}

	return ret;
}