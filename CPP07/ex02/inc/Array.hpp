#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;

	public:
		Array();
		~Array();
		Array(const Array& toCopy);
		Array<T>& operator=(const Array& toCopy);

		Array<T> operator[](int indx);

		Array(unsigned int size);

		unsigned int size();
};

#include "../src/Array.tpp"

#endif