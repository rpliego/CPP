#include <iostream>
#include <iomanip>
#include "Contact.hpp"

Contact::Contact(void)
{}

Contact::~Contact(void)
{}

void	Contact::new_contact (void)
{
	std::string input;

	while (1)
	{
		std::cout << "First name: ";
		if (!std::getline(std::cin, input))
			exit(1);
		_first_name = input;

		std::cout << "Last name: ";
		if (!std::getline(std::cin, input))
			exit(1);
		_last_name = input;

		std::cout << "Nickname: ";
		if (!std::getline(std::cin, input))
			exit(1);
		_nickname = input;

		std::cout << "Phone number: ";
		if (!std::getline(std::cin, input))
			exit(1);
		_phone_number = input;

		std::cout << "Dark secret: ";
		if (!std::getline(std::cin, input))
			exit(1);
		_dark_secret = input;
		if (!_first_name.length() || !_last_name.length() || !_nickname.length()
			|| !_phone_number.length() || !_dark_secret.length())
			std::cout << std::endl << "\x1b[31mFill all the contact\x1b[0m" << std::endl << std::endl;
		else
			return ;
	}
}

void	Contact::show_index(int index)
{
	std::cout << std::setw(10) << index << "|";
	if (this->_first_name.length() > 10)
		std::cout << std::setw(9) << this->_first_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->_first_name << "|";
	if (this->_last_name.length() > 10)
		std::cout << std::setw(9) << this->_last_name.substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << this->_last_name << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::setw(9) << this->_nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << std::setw(10) << this->_nickname << std::endl;
}