#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		int			_countFloor;
		AMateria*	_slots[4];
		AMateria**	_floor;
	public:
		Character();
		Character(std::string name);
		Character(const Character& toCopy);
		~Character();

		Character&	operator=(const Character& toCopy);

		std::string const & getName() const;
		void		equip(AMateria* m);
		void		unequip(int	indx);
		void		use(int	indx, ICharacter& target);
};

#endif