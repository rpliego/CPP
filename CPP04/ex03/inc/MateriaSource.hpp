#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _slots[4];

	public:
		MateriaSource();
		~MateriaSource();
		MateriaSource(const MateriaSource& toCopy);

		MateriaSource& operator=(const MateriaSource& toCopy);

		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif