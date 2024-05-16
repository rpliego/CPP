#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie();

		void	announce(void);

	private:
		std::string _name;
};

Zombie *newZombie(std::string name);
void	ramdomChump(std::string name);

#endif