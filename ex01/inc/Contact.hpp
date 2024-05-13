#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <cstdlib>

class Contact
{
public:
	Contact();
	~Contact();

	void	new_contact();
	void	show_index(int index);
	void	show_contact();
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string _phone_number;
	std::string _dark_secret;

};

#endif