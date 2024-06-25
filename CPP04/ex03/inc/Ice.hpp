#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& toCopy);

		Ice& operator=(const Ice& toCopy);
		AMateria* clone() const;
};

#endif