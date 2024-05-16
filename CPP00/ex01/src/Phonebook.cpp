#include <iostream>
#include "Contact.hpp"
#include "Phonebook.hpp"

Phonebook::Phonebook(){ _index = 0; _counter = 0;}

Phonebook::~Phonebook() {}

void	Phonebook::add(void)
{
	if (_index == 8)
		_index = 0;
	_contacts[_index].new_contact();
	_index++;
	_counter++;
}

void	Contact::show_contact()
{
	std::cout << std::endl;
	std::cout << "First name: " <<this->_first_name << std::endl;
	std::cout << "Last name: " << this->_last_name << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phone_number << std::endl;
	std::cout << "Dark secret: "<< this->_dark_secret << std::endl;
	std::cout << std::endl;
}

void	Phonebook::search(void)
{
	int	i = 0;
	std::string input;

	if (_counter == 0){
		std::cout << "\x1b[31mPhonebook its empty\x1b[0m" << std::endl;
		return ;
	}
	std::cout << "\x1b[33;1m           AWESOME PHONEBOOK\x1b[0m" << std::endl;
	std::cout << "\x1b[33;1m-------------------------------------------\x1b[0m" << std::endl;
	while (i < _counter && i < 8)
	{
		_contacts[i].show_index(i + 1);
		i++;
	}

	std::cout << std::endl << "\x1b[33;1mEnter an index: \x1b[0m";
	if (!std::getline(std::cin, input))
		exit(1);
	i = atoi(input.c_str()) - 1;
	if (i < _counter && i >= 0 && i < 8)
		_contacts[i].show_contact();
	else
		std::cout << "\x1b[31mInvalid Index\x1b[0m" << std::endl;
}