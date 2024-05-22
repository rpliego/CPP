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
	void (Harl::* fptr[4])() = 
	{
		&Harl::_debug,
		&Harl::_info,
		&Harl::_warning,
		&Harl::_error
	};

	std::string	aux[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR" 
	};

	for (int i = 0; i < 4; i++)
	{
		if (aux[i] == level)
		{
			(this->* fptr[i])();
			return ;
		}
	}
	
	std::cout << "???????????????" << std::endl;
}
