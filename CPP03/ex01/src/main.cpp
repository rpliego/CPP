#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main()
{
	std::cout << "--------------------------------------" << std::endl;

	ScavTrap boby("Bob");

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	
	boby.attack("victim");
	std::cout << "h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	boby.takeDamage(7);
	std::cout << "h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	boby.beRepaired(42);
	std::cout << "h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	boby.guardGate();
	std::cout << "h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	ScavTrap boby2(boby);
	boby2.nameSetter("Boby 2");
	std::cout << "--------------------------------------" << std::endl;

	std::cout << "guardgate() of boby2:" << std::endl;
	boby2.guardGate();
	std::cout << "boby : h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "boby2 : h.p.: " << boby2.statsGetter(HITPOINTS) << " e.p.: " << boby2.statsGetter(ENERGIPOINTS) << " d.: " << boby2.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	boby.takeDamage(10);
	boby2.beRepaired(100);
	std::cout << "boby : h.p.: " << boby.statsGetter(HITPOINTS) << " e.p.: " << boby.statsGetter(ENERGIPOINTS) << " d.: " << boby.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "boby2 : h.p.: " << boby2.statsGetter(HITPOINTS) << " e.p.: " << boby2.statsGetter(ENERGIPOINTS) << " d.: " << boby2.statsGetter(ATTACKDAMAGE) << std::endl;
	std::cout << "--------------------------------------" << std::endl;

}