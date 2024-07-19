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
	if (this->_size)
		delete[] this->_data;
}

template <typename T>
Array<T>::Array(const Array& toCopy)
{
	std::cout << "Array Copy Constructor called" << std::endl;

	this->_size = toCopy._size;
    if (toCopy._size != 0)
	{
		this->_data = new T[this->_size];
		for (int i = 0; i < (int)toCopy._size; i ++)
			this->_data[i] = toCopy._data[i];
	}
	else
		this->_data = NULL;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& toCopy)
{
	std::cout << "Array = overload called" << std::endl;
	if (this->_size > 0)
		delete[] this->_data;
	this->_size = toCopy._size;
	this->_data = new T[toCopy._size];

	for (size_t i = 0; i < this->_size; i++)
	{
		this->_data[i] = toCopy._data[i];
	}
	
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int indx) const
{
	if (indx < 0 || indx >= this->_size)
		throw std::exception();
	return this->_data[indx];
}

template <typename T>
Array<T>::Array(unsigned int size)
{
	std::cout << "Array Parametized Constructor called" << std::endl;
	this->_size = size;
	this->_data = new T[size];

	for (unsigned int i = 0; i < size; i++)
		this->_data[i] = 0;
	
}

template <typename T>
unsigned int	Array<T>::size() {return this->_size;}