#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

void	main_prompt()
{
	std::cout << "\x1b[44;37mEnter one of the following commands:\x1b[0m" << std::endl;
	std::cout << "\x1b[32m-> ADD:\x1b[0m to save a new contact" << std::endl;
	std::cout << "\x1b[32m-> SEARCH:\x1b[0m to display a specific contact"  << std::endl;
	std::cout << "\x1b[32m-> Exit:\x1b[0m to exit the phonebook" << std::endl << std::endl;
	std::cout << "->";
}

int	main(int ac, char **av)
{
	(void)av;
	std::string input;
	Phonebook phonebook;

	if (ac != 1) {
		std::cout << "No arguments here" << std::endl;
		return (1);
	}

	while (1)
	{
		main_prompt();
		if (!std::getline(std::cin, input))
			return (1);
		else if (input == "ADD")
			phonebook.add();
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			return (0);
		else if (input.length() == 0)
			std::cout << "\x1b[31mEnter something pls\x1b[0m" << std::endl << std::endl;
		else
			std::cout << "\x1b[31mInvalid input\x1b[0m" << std::endl << std::endl;
	}
	
}