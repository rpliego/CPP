#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"
#include "../inc/DiamondTrap.hpp"

int	main()
{
	std::cout << "--------------------------------------" << std::endl;

	DiamondTrap di("Diamond");

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	
	di.attack("victim");
	std::cout << "h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	di.takeDamage(7);
	std::cout << "h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	di.beRepaired(42);
	std::cout << "h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	di.whoAmI();
	std::cout << "h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	DiamondTrap di2(di);
	std::cout << "whoAmI() of Di2:" << std::endl;
	di2.whoAmI();
	std::cout << "Di : h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "Di2 : h.p.: " << di2.statsGetter(HITPOINTS) << " e.p.: " << di2.statsGetter(ENERGIPOINTS) << " d.: " << di2.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	di.takeDamage(10);
	di2.beRepaired(100);
	std::cout << "Di : h.p.: " << di.statsGetter(HITPOINTS) << " e.p.: " << di.statsGetter(ENERGIPOINTS) << " d.: " << di.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "Di2 : h.p.: " << di2.statsGetter(HITPOINTS) << " e.p.: " << di2.statsGetter(ENERGIPOINTS) << " d.: " << di2.statsGetter(ATTACKDAMAGE) << std::endl;
	// std::cout << "--------------------------------------" << std::endl;

	return (0);

}