#include "../inc/Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Default Constructor called" << std::endl;
	this->_data = new T[0];
	this->_size = 0;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array Default Destructor called" << std::endl;
	if (this->_data)
		delete[] this->_data;
}

template <typename T>
Array<T>::Array(const Array& toCopy)
{
	std::cout << "Array Copy Constructor called" << std::endl;
	*this = toCopy;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& toCopy)
{
	std::cout << "Array = overload called" << std::endl;
	this->_size = toCopy._size;
	this->_data = new T[(*(toCopy._data))];

	return *this;
}

template<typename T>
Array<T>	Array<T>::operator[](int indx)
{
	if (indx < 0 || indx >= static_cast<int>(this->_size))
		throw std::exception();
	return this->_data[indx];
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	if (size < 0)
		throw std::exception();
	std::cout << "Array Parametized Constructor called" << std::endl;
	this->_size = size;
	this->_data = new T[size];

	for (unsigned int i = 0; i < size; i++)
		this->_data[i] = 0;
	
}

template <typename T>
unsigned int	Array<T>::size() {return this->_size;}