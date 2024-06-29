#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
    protected:
        std::string _type;

    public:
        AMateria();
        virtual ~AMateria();
        AMateria(const AMateria& toCopy);
        AMateria&   operator=(const AMateria& toCopy);

        AMateria(std::string const & type);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif