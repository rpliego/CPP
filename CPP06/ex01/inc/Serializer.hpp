#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& toCopy);
		Serializer& operator=(const Serializer& toCopy);
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif