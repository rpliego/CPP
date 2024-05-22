#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void	Harl::_debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl 
	<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
	<< std::endl;
}

void	Harl::_info(void)
{
	std::cout << "[ INFO ]" << std::endl 
	<< "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!"
	<< std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "[ WARNING ]" << std::endl 
	<< "I think I deserve to have some extra bacon for free. I ve been coming for years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::_error(void)
{
	std::cout << "[ ERROR ]" << std::endl 
	<< "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = -1;
	void (Harl::*fptr[4])();
	std::string	aux[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR" 
	};

	fptr[0] = &Harl::_debug;
	fptr[1] = &Harl::_info;
	fptr[2] = &Harl::_warning;
	fptr[3] = &Harl::_error;

	while (++i < 4)
	{
		if (aux[i] == level)
		{
			(this->*fptr[i])();
			return ;
		}
	}
	std::cout << "???????????????" << std::endl;
}
