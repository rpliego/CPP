#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main()
{
	FragTrap aux("BOB");
	FragTrap bob(aux);
    int i = 0;
	std::cout << "--------------------------------------" << std::endl;
    bob.attack("william");
    bob.takeDamage( 5 );
    bob.beRepaired( 11 );
	std::cout << "--------------------------------------" << std::endl;
    bob.highFiveGuys();
	std::cout << "--------------------------------------" << std::endl;
    while (i < 5)
    {
        bob.attack("himself");
        bob.takeDamage( bob.statsGetter(ATTACKDAMAGE) );
		std::cout << "--------------------------------------" << std::endl;
        i++;
    }
    return (0);
}