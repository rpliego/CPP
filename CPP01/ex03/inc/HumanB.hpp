#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB();
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &new_weapon);

	private:
		std::string _name;
		Weapon		*_weapon;
};

#endif